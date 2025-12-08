class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int i = 3; i < n ; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = i * i + j * j;
                int sq = sqrt(sum);
                if (sum == sq * sq && sq <= n) {
                    res += 2;
                }
            }
        }
        return res;
    }
};