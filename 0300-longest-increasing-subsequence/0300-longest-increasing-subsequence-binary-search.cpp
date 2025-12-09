class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        
        for (int num : nums) {
            if (tails.empty() || num > tails.back()) {
                tails.push_back(num);
            } 
            else {
                auto it = lower_bound(tails.begin(), tails.end(), num);
                *it = num;
            }
        }
        
        return tails.size();
    }
};