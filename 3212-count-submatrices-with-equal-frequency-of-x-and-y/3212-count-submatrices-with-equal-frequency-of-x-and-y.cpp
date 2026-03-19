class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dp0(n+1, {0, 0}), dp(n+1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int addX = (grid[i][j] == 'X') ? 1 : 0;
                int addY = (grid[i][j] == 'Y') ? 1 : 0;

                dp[j + 1].first = dp[j].first + dp0[j + 1].first - dp0[j].first + addX;
                dp[j + 1].second = dp[j].second + dp0[j + 1].second - dp0[j].second + addY;

                if (dp[j + 1].first != 0 && dp[j + 1].first == dp[j + 1].second)
                    ans++;
            }
            dp0 = dp;
            dp[0] = {0, 0};
        }
        return ans;
    }
};