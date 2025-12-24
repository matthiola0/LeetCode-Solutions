class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> cur;
        backtrack(candidates, target, cur, 0, res);
        return res;
    }
private: 
    void backtrack(vector<int>& candidates, int target, vector<int>& cur, int idx, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (target < candidates[i]) break;
            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], cur, i, res);
            cur.pop_back();
        }
    }
};