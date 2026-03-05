class Solution {
public:
    int minOperations(string s) {
        int alternating = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2) {
                if (s[i] == '1') alternating++;
            } else {
                if (s[i] == '0') alternating++;
            }
        }

        return min(alternating, (int)s.size() - alternating);
    }
};