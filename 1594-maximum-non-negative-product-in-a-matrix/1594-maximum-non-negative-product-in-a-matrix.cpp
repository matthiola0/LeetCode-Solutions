class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mod = 1e9 + 7;
        
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n));
        
        dp[0][0] = {grid[0][0], grid[0][0]};
        
        for (int i = 1; i < m; i++) {
            dp[i][0].first = dp[i-1][0].first * grid[i][0];
            dp[i][0].second = dp[i-1][0].second * grid[i][0];
        }
        
        for (int j = 1; j < n; j++) {
            dp[0][j].first = dp[0][j-1].first * grid[0][j];
            dp[0][j].second = dp[0][j-1].second * grid[0][j];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long max_prev = max(dp[i-1][j].first, dp[i][j-1].first);
                long long min_prev = min(dp[i-1][j].second, dp[i][j-1].second);
                
                if (grid[i][j] < 0) {
                    dp[i][j].first = min_prev * grid[i][j];
                    dp[i][j].second = max_prev * grid[i][j];
                } else {
                    dp[i][j].first = max_prev * grid[i][j];
                    dp[i][j].second = min_prev * grid[i][j];
                }
            }
        }
        
        if (dp[m-1][n-1].first < 0) return -1;
        return dp[m-1][n-1].first % mod;
    }
};