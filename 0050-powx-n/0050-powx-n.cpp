class Solution {
private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        double tmp = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return tmp * tmp;
        } else {
            return tmp * tmp * x;
        }
    }
    
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        long long N = n;        
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
};