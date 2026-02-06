class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n;
        int right = 1;
        for (int i = 0; i < n; i++) {
            while (right < n && nums[right] <= nums[i] * k) right++;
            ans = min(ans, i + n - right);
        }

        return ans;
    }
};