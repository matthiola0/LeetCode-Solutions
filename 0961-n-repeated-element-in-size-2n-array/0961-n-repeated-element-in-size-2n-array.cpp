class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> element;
        for (int i: nums) {
            if (element.count(i)) return i;
            element.insert(i);
        }
        return 0;
    }
};