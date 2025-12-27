class Solution {
public:
    string convert(string s, int numRows) {
        int dir = 1, cur = 0;
        vector<string> v(numRows);
        for (int i = 0; i < s.size(); i++) {
            v[cur] += s[i];
            if (cur + dir == -1 || cur + dir == numRows) {
                dir *= -1;
            }
            cur += dir;
        }
        string res = "";
        for (string x : v) {
            res += x;
        }
        return res;
    }
};