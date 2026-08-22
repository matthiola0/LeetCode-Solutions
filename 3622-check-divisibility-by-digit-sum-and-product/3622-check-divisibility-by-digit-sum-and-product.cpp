class Solution {
public:
    bool checkDivisibility(int n) {
        int m = n;
        int sum = 0, prod = 1;
        while (m > 0) {
            int cur = m % 10;
            sum += cur;
            prod *= cur;
            m /= 10;
        }
        return (n % (sum + prod)) == 0;
    }
};