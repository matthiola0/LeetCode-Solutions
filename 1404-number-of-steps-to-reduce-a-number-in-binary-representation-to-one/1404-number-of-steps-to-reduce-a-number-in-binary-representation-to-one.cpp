class Solution {
public:
    int numSteps(string s) {
        int cnt = 0, carry = 0;
        for (int i = s.size() - 1; i > 0; i--) {
            if (carry + (s[i] == '1') == 1) {
                cnt += 2;
                carry = 1;
            } else {
                cnt += 1;
            }
        }
        return cnt + carry;
    }
};