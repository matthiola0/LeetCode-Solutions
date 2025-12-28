class Solution {
private:
    void backtrack(vector<vector<int>> &res, vector<int> &cur, int j, int n, int k) {
        if (cur.size() == k) res.push_back(cur);
        for (int i = j; i <= n; i++) {
            cur.push_back(i);
            backtrack(res, cur, i + 1, n, k);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(res, cur, 1, n, k);
        return res;
    }
};