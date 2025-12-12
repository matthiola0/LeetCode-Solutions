class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i != 0 && dp[i-1] > 0) 
                dp[i] = dp[i-1] + nums[i];
            else dp[i] = nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};
