class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int left = 1;
        vector<int> right(nums);
        for (int i = nums.size() - 2; i >= 0; i--) 
            right[i] *= right[i+1];
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1) ans.push_back(left);
            else ans.push_back(left * right[i+1]);
            left *= nums[i];
        }
        return ans;
    }
};

