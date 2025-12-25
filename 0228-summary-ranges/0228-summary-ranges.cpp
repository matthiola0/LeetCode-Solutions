class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<string> res;
        int start = 0, end = 0;
        string s;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) {
                end = i;
            } else {
                if (start == end) s = to_string(nums[end]);
                else s = to_string(nums[start]) + "->" + to_string(nums[end]);
                res.push_back(s);
                start = i;
                end = i;
            }
        }
        if (start == end) s = to_string(nums[end]);
        else s = to_string(nums[start]) + "->" + to_string(nums[end]);
        res.push_back(s);

        return res;
    }
};