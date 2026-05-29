class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int cur = 0;
            while (nums[i] > 0) {
                cur += nums[i] % 10;
                nums[i] /= 10;
            }
            res = min(res, cur);;
        }

        return res;
    }
};