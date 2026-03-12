class DSU {
public:
    vector<int> parent;
    int components;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        components = n;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        long long min_must_strength = 2e14; // 給一個夠大的初始值
        long long max_val = 0;

        // 1. 前置檢查：確保 mandatory edges 不會形成 cycle
        DSU initial_dsu(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            long long s = e[2];
            int must = e[3];
            
            max_val = max(max_val, s * 2); // 紀錄圖中可能出現的最大強度 (升級後)
            
            if (must == 1) {
                if (!initial_dsu.unite(u, v)) {
                    return -1; // 必選邊形成 Cycle，絕對無法形成合法的 Spanning Tree
                }
                min_must_strength = min(min_must_strength, s);
            }
        }

        // 2. 前置檢查：確保給定的所有邊加起來能夠連通所有節點
        DSU check_conn(n);
        for (const auto& e : edges) {
            check_conn.unite(e[0], e[1]);
        }
        if (check_conn.components > 1) {
            return -1; // 所有邊都用上也連不起來
        }

        // 3. 二分搜尋
        long long left = 0;
        // 最大不可能超過「所有可能升級後的最大值」以及「必選邊的最小值」
        long long right = min(max_val, min_must_strength);
        long long ans = -1;

        // check 函數：檢查目標 stability x 是否可行
        auto check = [&](long long x) {
            DSU dsu(n);
            
            // Step 1: 先強制加入所有 must == 1 的邊 (前面已保證不會有 cycle)
            for (const auto& e : edges) {
                if (e[3] == 1) {
                    dsu.unite(e[0], e[1]);
                }
            }
            
            // Step 2: 加入所有 must == 0 且 strength >= x 的「免費邊」
            for (const auto& e : edges) {
                if (e[3] == 0 && e[2] >= x) {
                    dsu.unite(e[0], e[1]);
                }
            }

            // Step 3: 加入 must == 0 且 strength < x 但 strength * 2 >= x 的「需升級邊」
            int upgrades_used = 0;
            for (const auto& e : edges) {
                if (e[3] == 0 && e[2] < x && e[2] * 2 >= x) {
                    // 只要加入後不形成 Cycle，就花費一次升級額度
                    if (dsu.unite(e[0], e[1])) {
                        upgrades_used++;
                    }
                }
            }

            // 如果全部點都連通了，且使用的升級次數沒有超標，就代表這個 x 是可以達成的
            return dsu.components == 1 && upgrades_used <= k;
        };

        // 執行 Binary Search
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) {
                ans = mid;      // 記錄當前合法解
                left = mid + 1; // 嘗試找更大的極值
            } else {
                right = mid - 1; // 當前 x 太嚴苛，縮小範圍
            }
        }

        return ans;
    }
};