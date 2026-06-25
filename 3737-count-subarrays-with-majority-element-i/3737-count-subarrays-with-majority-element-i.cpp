class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int score = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    score++;
                } else {
                    score--;
                }
                if (score > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};