class Solution {
public:
    int numTrees(int n) {
        static vector<int> dp(20);
        static int idx = 3;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        if (dp[n] != 0) return dp[n];
        for (int i = idx; i <= n; i++) {
            for (int j = 0; j <= i-1; j++) {
                dp[i] += dp[j] * dp[i-1-j];
            }
        }
        idx = n + 1;
        return dp[n];
    }
};