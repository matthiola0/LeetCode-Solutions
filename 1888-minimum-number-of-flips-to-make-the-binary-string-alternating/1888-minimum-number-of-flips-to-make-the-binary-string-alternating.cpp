class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int diff1 = 0, diff2 = 0;
        int ans = n;

        for (int i = 0; i < 2 * n; i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if (s[i % n] != expected1) diff1++;
            if (s[i % n] != expected2) diff2++;

            if (i >= n) {
                int left_idx = i - n;
                char left_expected1 = (left_idx % 2 == 0) ? '0' : '1';
                char left_expected2 = (left_idx % 2 == 0) ? '1' : '0';
                
                if (s[left_idx % n] != left_expected1) diff1--;
                if (s[left_idx % n] != left_expected2) diff2--;
            }

            if (i >= n - 1) {
                ans = min({ans, diff1, diff2});
            }
        }
        return ans;
    }
};