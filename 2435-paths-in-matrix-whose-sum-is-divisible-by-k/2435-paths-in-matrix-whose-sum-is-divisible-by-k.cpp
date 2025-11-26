class Solution {
private:
    int mod = 1e9 + 7;
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        int idx;
        idx = grid[0][0] % k;
        dp[0][0][idx] = 1;
        for (int i = 1; i < n; i++) {
            idx = (idx + grid[i][0]) % k;
            dp[i][0][idx] = 1;
        }
        idx = grid[0][0] % k;
        for (int j = 1; j < m; j++) {
            idx = (idx + grid[0][j]) % k;
            dp[0][j][idx] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                for (int a = 0; a < k; a++) {   // [i-1][j]
                    if (dp[i-1][j][a] != 0) {
                        int idx = (a + grid[i][j]) % k;
                        dp[i][j][idx] = (dp[i][j][idx] + dp[i-1][j][a]) % mod;
                    }
                }
                for (int a = 0; a < k; a++) {   // [i][j-1]
                    if (dp[i][j-1][a] != 0) {
                        int idx = (a + grid[i][j]) % k;
                        dp[i][j][idx] = (dp[i][j][idx] + dp[i][j-1][a]) % mod;
                    }
                }
            }
        }

        return dp[n-1][m-1][0];
    }
};