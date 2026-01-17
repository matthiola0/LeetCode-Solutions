class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for (int k = 1; ; ++k) {
            long long triangular_sum = 1LL * k * (k - 1) / 2;
            
            long long remaining = n - triangular_sum;
            
            if (remaining <= 0) break;
            
            if (remaining % k == 0) {
                count++;
            }
        }
        return count;
    }
};