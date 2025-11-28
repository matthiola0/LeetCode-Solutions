class Solution {
private:
    void dfs(int u, int p, vector<vector<int>> &G, stack<int> &s, vector<int> &parent) {
        parent[u] = p;
        s.push(u);
        for (auto v : G[u]) {
            if (v == p) continue;
            dfs(v, u, G, s, parent);
        }
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> G(n);
        for (auto edge : edges) {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        stack<int> s;
        vector<int> parent(n);

        dfs(0, -1, G, s, parent);
        vector<long long> sum(n);
        for (int i = 0; i < n; i++) sum[i] = values[i];

        int ans = 0;
        while (!s.empty()) {
            int u = s.top(); s.pop();
            if (sum[u] % k == 0) {
                ans += 1;
            } else {
                sum[parent[u]] += sum[u];
            }
        }
        return ans;
    }
};