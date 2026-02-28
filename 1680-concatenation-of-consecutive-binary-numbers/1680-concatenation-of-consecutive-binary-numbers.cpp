class Solution {
    int mod = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int shift = 0;
            int num = i;
            while (num > 0) {
                num >>= 1;
                shift++;
            }

            ans = ((ans << shift) % mod + i) % mod;
        }
        return (int)ans;
    }
};