class Solution {
public:
    int change(int amount, vector<int>& coins) {    // 組合 vs. 377. 排列
        vector<unsigned long long> dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};