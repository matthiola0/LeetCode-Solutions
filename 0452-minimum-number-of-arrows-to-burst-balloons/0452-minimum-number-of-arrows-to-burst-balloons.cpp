class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int res = 1, last = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > last) {
                last = points[i][1];
                res++;
            } else {
                last = min(last, points[i][1]);
            }
        }
        return res;
    }
};