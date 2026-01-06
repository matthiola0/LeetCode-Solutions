class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> dp(maxVal + 1);
        for (int x: nums) {
            dp[x] += x;
        }

        dp[1] = max(dp[1], dp[0]);
        for (int i = 2; i <= maxVal; i++) {
            int point = dp[i];
            dp[i] = max(dp[i-1], dp[i-2] + point);
        }

        return dp[maxVal];
    }
};