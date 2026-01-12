class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> cnt;
            for (int j = i+1; j < n; j++) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int d = gcd(dx, dy);

                int nx = dx/d, ny = dy/d;

                if (nx < 0 || (nx == 0 && ny < 0)) {
                    nx = -nx;
                    ny = -ny;
                }

                string key = to_string(nx) + '_' + to_string(ny);
                
                if (cnt.count(key)) {
                    cnt[key]++;
                    res = max(res, cnt[key]);
                } else {
                    cnt[key] = 2;
                    res = max(res, cnt[key]);
                }
            }
        }
        return res;
    }
};