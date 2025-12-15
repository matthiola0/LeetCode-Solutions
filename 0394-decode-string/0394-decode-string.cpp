class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> stk;
        string curString = "";
        int curNum = 0;
        for (char c : s) {
            if (isdigit(c)) {
                curNum = curNum * 10 + (c - '0');
            } else if (c == '[') {
                stk.push({curString, curNum});
                curString = "";
                curNum = 0;
            } else if (c == ']') {
                auto [prevStr, times] = stk.top();
                stk.pop();

                string tmp = "";
                while (times--) {
                    tmp += curString;
                }
                curString = prevStr + tmp;
            } else {
                curString += c;
            }
        }
        return curString;
    }
};