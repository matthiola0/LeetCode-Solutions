class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> max_num(n), min_num(n);
        max_num[0] = nums[0]; min_num.back() = nums.back();

        for (int i = 1; i < n; i++) {
            max_num[i] = max(max_num[i - 1], nums[i]);
            min_num[n - i - 1] = min(min_num[n - i], nums[n - i - 1]);
        }

        for (int i = 0; i < n; i++) {
            if (max_num[i] - min_num[i] <= k) return i;
        }

        return -1;
    }
};