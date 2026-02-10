class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> even_set;
            unordered_set<int> odd_set;

            for (int j = i; j < n; ++j) {
                int val = nums[j];

                if (val % 2 == 0) {
                    even_set.insert(val);
                } else {
                    odd_set.insert(val);
                }

                if (even_set.size() == odd_set.size()) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};