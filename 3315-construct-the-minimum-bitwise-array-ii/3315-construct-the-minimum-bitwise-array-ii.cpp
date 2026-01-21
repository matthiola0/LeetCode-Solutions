class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        
        for (int x : nums) {
            if (x == 2) {
                ans.push_back(-1);
            } else {
                // x 是奇數，x+1 是偶數
                // 例如 x = 10111 (23), x+1 = 11000 (24)
                // 24 的 lowbit 是 1000 (8)
                // 我們要減去的是 100 (4)
                // 使用 x + 1 找到 lowest set bit
                long long temp = (long long)x + 1;
                long long lowbit = temp & -temp;
                
                ans.push_back(x - (lowbit >> 1));
            }
        }
        return ans;
    }
};