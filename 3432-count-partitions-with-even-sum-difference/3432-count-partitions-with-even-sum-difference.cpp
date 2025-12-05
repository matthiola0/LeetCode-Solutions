class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 == 0) {
            return nums.size() - 1;
        } else {
            return 0;
        }
    }
};