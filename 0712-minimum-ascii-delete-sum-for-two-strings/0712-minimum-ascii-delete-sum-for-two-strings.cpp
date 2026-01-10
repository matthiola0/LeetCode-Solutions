class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return minimumDeleteSum(s2, s1);

        vector<int> dp(n + 1);
        for (int j = 0; j < n; j++) {
            dp[j+1] = dp[j] + s1[j];
        }

        for (int i = 0; i < m; i++) {
            int diag = dp[0];
            dp[0] += s2[i];

            for (int j = 0; j < n; j++) {
                int next_diag = dp[j+1];

                if (s2[i] == s1[j]) {
                    dp[j+1] = diag;
                } else {
                    dp[j+1] = min(dp[j] + s1[j], dp[j+1] + s2[i]);
                }

                diag = next_diag;
            }
        }

        return dp[n];
    }
};