class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string& item : tokens) {
            if (item != "+" && item != "-" && item != "*" && item != "/") {
                stk.push(stoi(item));
            } else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                if (item == "+") {
                    stk.push(a + b);
                } else if (item == "-") {
                    stk.push(a - b);
                } else if (item == "*") {
                    stk.push(a * b);
                } else if (item == "/") {
                    stk.push(a / b);
                }
            }
        }
        return stk.top();
    }
};