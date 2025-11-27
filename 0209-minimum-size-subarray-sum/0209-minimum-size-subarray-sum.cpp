class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_l = INT_MAX;
        int left = 0;
        int cur_sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            cur_sum += nums[right];

            while (cur_sum >= target) {
                min_l = min(min_l, right - left + 1);
                cur_sum -= nums[left];
                left++;
            }
        }

        return min_l == INT_MAX ? 0 : min_l;
    }
};