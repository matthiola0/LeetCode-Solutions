class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];

            auto it = window.lower_bound(cur - valueDiff);
            if (it != window.end() && *it <= cur + valueDiff)
                return true;
            
            window.insert(cur);
            if (window.size() > indexDiff) {
                window.erase(nums[i-indexDiff]);
            }
        }
        return false;
    }
};