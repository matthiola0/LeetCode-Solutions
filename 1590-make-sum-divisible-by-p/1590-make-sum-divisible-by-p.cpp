class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin(), nums.end(), 0);
        int target = total % p;
        if (target == 0) return 0;

        unordered_map<int, int> hash;   // remainder, last index
        hash[0] = -1;
        long long cur_sum = 0;
        int min_len = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            int cur_mod = cur_sum % p;

            // (cur_mod - needed) % p = target
            int needed = (cur_mod - target + p) % p;
            if (hash.find(needed) != hash.end()) {
                min_len = min(min_len, i - hash[needed]);
            }
            hash[cur_mod] = i;
        }
        return min_len == INT_MAX ? -1 : min_len;
    }
};