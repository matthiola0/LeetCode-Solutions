class Solution {
private:
    int calculate(int n) {
        string s = to_string(n);
        int l = s.size();
        if (l < 3) return 0;

        int res = 0;
        for (int i = 1; i < l - 1; i++) {
            int prev = s[i - 1] - '0';
            int curr = s[i] - '0';
            int next = s[i + 1] - '0';

            if (curr > prev && curr > next) {
                res++;
            } else if (curr < prev && curr < next) {
                res++;
            }
        }
        return res;
    }
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for (int i = num1; i <= num2; i++) {
            res += calculate(i);
        }
        return res;
    }
};