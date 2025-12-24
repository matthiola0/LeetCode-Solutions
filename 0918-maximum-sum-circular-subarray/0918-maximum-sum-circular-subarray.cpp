class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;

        int cur_max = 0, global_max = INT_MIN;
        int cur_min = 0, global_min = INT_MAX;

        for (int num : nums) {
            total_sum += num;
            
            cur_max += num;
            global_max = max(global_max, cur_max);
            if (cur_max < 0) cur_max = 0;

            cur_min += num;
            global_min = min(global_min, cur_min);
            if (cur_min > 0) cur_min = 0;
        }
        if (total_sum == global_min) return  global_max;
        return max(global_max, total_sum - global_min); 
    }
};