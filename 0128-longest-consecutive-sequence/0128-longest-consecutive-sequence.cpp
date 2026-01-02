class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longest = 0;
        for (int num: numSet) {
            if (numSet.count(num - 1)) continue;

            int curNum = num + 1;
            int curLen = 1;
            while (numSet.count(curNum)) {
                curLen++;
                curNum++;
            }
            longest = max(longest, curLen);
        }

        return longest;
    }
};