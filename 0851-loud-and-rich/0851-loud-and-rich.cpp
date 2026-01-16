class Solution {
    vector<vector<int>> adj;
    vector<int> memo;
    vector<int> quiet;

    int dfs(int i) {
        if (memo[i] != -1) return memo[i];

        int minNode = i;
        for (int rich : adj[i]) {
            int candidate = dfs(rich);
            if (quiet[candidate] < quiet[minNode]) {
                minNode = candidate;
            }
        }
        
        return memo[i] = minNode;
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        this->quiet = quiet;
        
        adj.resize(n);
        memo.assign(n, -1);
        
        for (auto& edge : richer) {
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = dfs(i);
        }
        
        return ans;
    }
};