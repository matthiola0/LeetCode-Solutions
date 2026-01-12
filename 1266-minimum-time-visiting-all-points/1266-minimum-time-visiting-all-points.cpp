class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;
        int lx = points[0][0], ly = points[0][1];
        int res = 0;
        for (int i = 1; i < n; i++) {
            int dx = abs(points[i][0] - lx),
                dy = abs(points[i][1] - ly);
            int smaller = min(dx, dy);
            res += smaller + (dx - smaller) + (dy - smaller);
            
            lx = points[i][0];
            ly = points[i][1];
        }
        return res;
    }
};