class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        vector<int> dp(n, 0);
        dp[n - 1] = stones[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            dp[i] = max(dp[i + 1], stones[i] - dp[i + 1]);
        }

        return dp[1];
    }
};