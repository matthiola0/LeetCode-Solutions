class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        int ans = 0;
        int cur = 0;
        while (n != 0) {
            if (n % 2 == 0) {
                ans += 1 << cur;
            }
            cur += 1;
            n >>= 1;
        }
        return ans;
    }
};