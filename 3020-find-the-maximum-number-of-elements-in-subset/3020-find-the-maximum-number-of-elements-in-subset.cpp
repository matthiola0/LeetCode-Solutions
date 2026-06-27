class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) count[num]++;
        
        int max_len = 1;
        
        for (auto const& [num, freq] : count) {
            if (num == 1) {
                int ones = count[1];
                if (ones % 2 == 0) ones--;
                max_len = max(max_len, ones);
                continue;
            }
            
            if (freq < 2) continue;
            
            int curr_len = 0;
            long long curr_num = num;
            
            while (count.count(curr_num) && count[curr_num] >= 2) {
                curr_len += 2;
                curr_num = curr_num * curr_num; 
            }
            
            if (count.count(curr_num) && count[curr_num] > 0) {
                curr_len += 1;
            } else {
                curr_len -= 1;
            }
            
            max_len = max(max_len, curr_len);
        }
        
        return max_len;
    }
};