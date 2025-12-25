class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int res = 1;
        for (int i = 0; i < n - 1; i++) {
            int local_max = 0;
            unordered_map<string, int> mp;
            for (int j = i + 1; j < n; j++) {
                int dy = points[j][1] - points[i][1],
                    dx = points[j][0] - points[i][0];
                int d = gcd(dx, dy);

                if (dy < 0) {dy = -dy; dx = -dx;}
                string key = to_string(dy/d) + '_' + to_string(dx/d);

                mp[key]++;
                local_max = max(local_max, mp[key]);
            }
            res = max(res, local_max + 1);
        }
        return res;
    }
};