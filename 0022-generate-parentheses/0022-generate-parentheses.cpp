class Solution {
private:
    void f(vector<string>& res, string cur, int open, int close, int n) {
        if (cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }
        if (open < n) {
            f(res, cur + '(', open + 1, close, n);
        }
        if (close < open) {
            f(res, cur + ')', open, close + 1, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        f(res, "", 0, 0, n);
        return res;
    }
};