class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        
        long long res = LLONG_MIN;
        vector<long long> min_val(k, LLONG_MAX);
        min_val[0] = 0;
        for (int i = 1; i <= n; i++) {
            int remainder = i % k;
            if (min_val[remainder] != LLONG_MAX) {
                res = max(res, pre[i] - min_val[remainder]);
            }

            min_val[remainder] = min(min_val[remainder], pre[i]);
        }
        return res;
    }
};