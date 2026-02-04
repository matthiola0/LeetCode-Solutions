class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        
        long long INF = -1e18; 
        
        long long inc1 = INF; // 第一段上升
        long long dec = INF;  // 中間段下降
        long long inc2 = INF; // 第二段上升
        
        long long ans = INF;
        
        for (int i = 1; i < n; ++i) {
            long long curr = nums[i];
            long long prev = nums[i-1];
            
            long long next_inc1 = INF;
            long long next_dec = INF;
            long long next_inc2 = INF;
            
            if (curr > prev) {
                next_inc1 = max(inc1 + curr, prev + curr);
                next_inc2 = max(inc2, dec) + curr;
                
            } else if (curr < prev) {
                next_dec = max(dec, inc1) + curr;
            }
            
            
            inc1 = next_inc1;
            dec = next_dec;
            inc2 = next_inc2;
            
            ans = max(ans, inc2);
        }
        
        return ans;
    }
};