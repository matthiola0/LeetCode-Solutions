class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_num = 0;
        long mul = 1;   // no zero
        vector<int> res;
        for (const int &num : nums) {
            if (num == 0) zero_num++;
            else mul *= num;
        }
        for (const int &num : nums) {
            if (zero_num > 1) res.push_back(0);
            else if (zero_num == 1) {
                if (num == 0) res.push_back(mul);
                else res.push_back(0);
            } else {
                res.push_back(mul/num);
            }
        }
        return res;
    }
};