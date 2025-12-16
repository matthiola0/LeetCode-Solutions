class Solution {
private:
    vector<vector<int>> adj;
    vector<int> m_present;
    vector<int> m_future;
    int m_budget;
    const int INF = -1e9;

    pair<vector<int>, vector<int>> dfs(int u) {
        vector<int> dp0(m_budget + 1, INF);
        vector<int> dp1(m_budget + 1, INF);
        dp0[0] = 0;
        dp1[0] = 0;

        for (int v : adj[u]) {
            auto [child_dp0, child_dp1] = dfs(v);
            // 1. u no buy
            vector<int> v_contrib0(m_budget + 1, INF);
            // v no buy
            for (int c = 0; c <= m_budget; ++c) v_contrib0[c] = child_dp0[c];
            // v buy (original price)
            int cost_full = m_present[v];
            int profit_full = m_future[v] - cost_full;
            for (int c = 0; c <= m_budget - cost_full; ++c) {
                if (child_dp1[c] > INF) {
                    v_contrib0[c + cost_full] = max(v_contrib0[c + cost_full], child_dp1[c] + profit_full);
                }
            }

            vector<int> new_dp0(m_budget + 1, INF);
            for (int i = 0; i <= m_budget; ++i) {
                if (dp0[i] == INF) continue;
                for (int j = 0; j <= m_budget - i; ++j) {
                    if (v_contrib0[j] > INF) {
                        new_dp0[i + j] = max(new_dp0[i + j], dp0[i] + v_contrib0[j]);
                    }
                }
            }
            dp0 = new_dp0;
            // 2. u buy
            vector<int> v_contrib1(m_budget + 1, INF);
            // v buy            
            for (int c = 0; c <= m_budget; ++c) v_contrib1[c] = child_dp0[c];
            // v buy (half price)
            int cost_half = m_present[v] / 2;
            int profit_half = m_future[v] - cost_half;
            for (int c = 0; c <= m_budget - cost_half; ++c) {
                if (child_dp1[c] > INF) {
                    v_contrib1[c + cost_half] = max(v_contrib1[c + cost_half], child_dp1[c] + profit_half);
                }
            }

            vector<int> new_dp1(m_budget + 1, INF);
            for (int i = 0; i <= m_budget; ++i) {
                if (dp1[i] == INF) continue;
                for (int j = 0; j <= m_budget - i; ++j) {
                    if (v_contrib1[j] > INF) {
                        new_dp1[i + j] = max(new_dp1[i + j], dp1[i] + v_contrib1[j]);
                    }
                }
            }
            dp1 = new_dp1;
        }
        return {dp0, dp1};
    }
    
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        this->m_present = present;
        this->m_future = future;
        this->m_budget = budget;

        adj.assign(n, vector<int>());
        for (const auto &edge: hierarchy) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
        }

        auto [root_dp0, root_dp1] = dfs(0);

        int ans = 0;
        // node 0 no buy
        for (int profit : root_dp0) {
            ans = max(ans, profit);
        }
        // node 0 buy
        int root_cost = m_present[0];
        int root_profit = m_future[0] - root_cost;
        for (int c = 0; c <= m_budget - root_cost; ++c) {
            if (root_dp1[c] > INF) {
                ans = max(ans, root_dp1[c] + root_profit);
            }
        }
        return ans;
    }
};