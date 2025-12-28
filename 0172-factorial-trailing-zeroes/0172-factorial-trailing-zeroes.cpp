class Solution {
public:
    int trailingZeroes(int n) {
        int five = 0;
        for (int i = 5; i <= n; i += 5) {
            int tmp = i;
            while (tmp % 5 == 0) {
                tmp /= 5;
                five++;
            }
        }
        return five;
    }
};