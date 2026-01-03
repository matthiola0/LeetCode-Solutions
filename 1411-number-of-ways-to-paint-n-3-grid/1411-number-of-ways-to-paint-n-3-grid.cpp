class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        long long a = 6, b = 6;

        for (int i = 2; i <= n; i++) {
            long long na = (2 * a + 2 * b) % mod;
            long long nb = (2 * a + 3 * b) % mod;
            a = na;
            b = nb;
        }

        return (a + b) % mod;
    }
};