class Solution {
public:
    int fib(int n) {
        static vector<int> f(31);
        static int i = 2;
        f[0] = 0; f[1] = 1;

        if (n < i) return f[n];

        for (;i <= n; i++) {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};