class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (!m.count(target - nums[i])) {
                m[nums[i]] = i;
            } else {
                return {m[target - nums[i]], i};
            }
        }
        return {0, 0};
    }
};