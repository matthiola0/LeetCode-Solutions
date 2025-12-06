class Solution {
private:
    int mod = 1e9 + 7;
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1);
        vector<int> prefix_dp(n + 1);
        deque<int> max_q, min_q;
        int left = 0;
        dp[0] = 1; prefix_dp[0] = 1;

        for (int i = 0 ; i < n; i++) {
            while (!max_q.empty() && nums[max_q.back()] <= nums[i]) {
                max_q.pop_back();
            }
            max_q.push_back(i);
            while (!min_q.empty() && nums[min_q.back()] >= nums[i]) {
                min_q.pop_back();
            }
            min_q.push_back(i);

            while (nums[max_q.front()] - nums[min_q.front()] > k) {
                left++;
                if (max_q.front() < left) {
                    max_q.pop_front();
                }
                if (min_q.front() < left) {
                    min_q.pop_front();
                }
            }

            long long cur = prefix_dp[i];
            if (left != 0) {
                cur = (cur - prefix_dp[left - 1] + mod) % mod;
            }
            dp[i + 1] = cur;
            prefix_dp[i + 1] = (prefix_dp[i] + dp[i + 1]) % mod;
        }
        return dp[n];
    }
};