class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums);
        if (n == 1) return dp[0];
        if (n == 2) return max(dp[0], dp[1]);
        
        dp[2] += dp[0];
        for(int i = 3; i < n; i++) {
            dp[i] += max(dp[i-2], dp[i-3]);
        }
        return max(dp[n-1], dp[n-2]);
    }
};