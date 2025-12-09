class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int sign = 1;
        long cur = 0;
        int res = 0;

        for (char c : s) {
            if (isdigit(c)) {
                cur = cur * 10 + c - '0';
            } else {
                switch(c) {
                    case '+':
                        res += sign * cur;
                        sign = 1;
                        cur = 0;
                        break;
                    case '-':
                        res += sign * cur;
                        sign = -1;
                        cur = 0;
                        break;
                    case '(':
                        stk.push(res);
                        stk.push(sign);
                        sign = 1;
                        res = 0;
                        cur = 0;
                        break;
                    case ')':
                        res += sign * cur;
                        res *= stk.top();
                        stk.pop();

                        res += stk.top();
                        stk.pop();
                        
                        sign = 1;
                        cur = 0;
                        break;
                    default:
                        break;
                }
            }
        }
        return res += sign * cur;
    }
};