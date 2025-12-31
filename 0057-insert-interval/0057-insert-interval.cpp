class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        for (auto i: intervals) {
            if (res.size() == 0 || i[0] > res.back()[1]) {
                res.push_back(i);
            } else {
                res.back()[1] = max(res.back()[1], i[1]);
            }
        }
        return res;
    }
};