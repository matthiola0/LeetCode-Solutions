class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        
        while (true) {
            bool is_sorted = true;
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] > nums[i + 1]) {
                    is_sorted = false;
                    break;
                }
            }
            
            if (is_sorted) {
                return operations;
            }
            
            long long min_sum = LLONG_MAX;
            int min_idx = -1;
            
            for (int i = 0; i < nums.size() - 1; ++i) {
                long long current_sum = (long long)nums[i] + nums[i + 1];
                if (current_sum < min_sum) {
                    min_sum = current_sum;
                    min_idx = i;
                }
            }
            
            nums[min_idx] = (int)min_sum;
            nums.erase(nums.begin() + min_idx + 1);
            
            operations++;
        }
    }
};