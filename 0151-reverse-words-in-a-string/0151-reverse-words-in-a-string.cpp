class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string cur;
        stack<string> stk;
        while (ss >> cur) {
            stk.push(cur);
        }
        
        if (stk.empty()) return "";

        string res = stk.top();
        stk.pop();
        while (!stk.empty()) {
            res += ' ' + stk.top();
            stk.pop();
        }

        return res;
    }
};