class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        stack<vector<int>> stk;
        for (auto i : intervals) {
            if (!stk.empty() && stk.top()[1] > i[0]) continue;
            stk.push(i);
        }
        return intervals.size() - stk.size();
    }
};