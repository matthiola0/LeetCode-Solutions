class Solution {
private:
    void f(vector<vector<int>>& res, vector<int>& nums, int cur) {
        if (cur == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size(); i++) {
            swap(nums[cur], nums[i]);
            f(res, nums, cur + 1);
            swap(nums[cur], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        f(res, nums, 0);
        return res;
    }
};