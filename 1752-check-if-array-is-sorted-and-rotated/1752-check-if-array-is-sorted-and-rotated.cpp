class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool rotate = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                if (!rotate && nums[n-1] <= nums[0]) {
                    rotate = true;
                } else return false;
            }
        }
        return true;
    }
};