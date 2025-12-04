class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 1;
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                dp[j+1][i+1] = dp[j+1][i];

                if (s[i] == t[j]) {
                    dp[j+1][i+1] += dp[j][i];
                }
            }
        }
        return dp[m][n];
    }
};