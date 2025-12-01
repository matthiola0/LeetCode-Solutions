class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {   // 排列 vs. 518. 組合
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};