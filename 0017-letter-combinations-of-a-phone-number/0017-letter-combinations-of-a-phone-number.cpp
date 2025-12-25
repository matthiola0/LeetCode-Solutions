class Solution {
private:
    vector<vector<char>> dict = {
        {'a', 'b', 'c'}, {'d', 'e', 'f'},
        {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
    };
    void dfs(const string& digits, string& cur, vector<string>& res, int idx) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }
        int i = digits[idx] - '2';
        for (int j = 0; j < dict[i].size(); j++) {
            cur.push_back(dict[i][j]);
            dfs(digits, cur, res, idx + 1);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string s = "";
        dfs(digits, s, res, 0);
        return res;
    }
};