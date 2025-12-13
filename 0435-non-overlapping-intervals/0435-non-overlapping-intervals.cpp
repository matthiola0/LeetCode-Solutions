class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int lastEnd = INT_MIN, cnt = 0;
        for (auto i : intervals) {
            if (lastEnd > i[0]) cnt++;
            else lastEnd = i[1];
        }
        return cnt;
    }
};