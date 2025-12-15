class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == ')') {
                if (stk.empty() || stk.top() != '(')
                    return false;
                stk.pop();
            } else if (c == '}') {
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
            } else if (c == ']') {
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        if (!stk.empty()) return false;
        return true;
    }
};