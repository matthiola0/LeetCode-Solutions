class Solution {
private:
    int count(unordered_map<int, unordered_map<int, int>>& mp) {
        int ans = 0;

        for (auto [k1, inner] : mp) {
            int sum = 0;

            for (auto [k2, val] : inner) {
                sum += val;
            }
            for (auto [k2, val] : inner) {
                ans += val * (sum -= val);
            }
        }
        return ans;
    }
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, unordered_map<int, int>> t, v;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                int g = gcd(dx, abs(dy));
                int sx = dx / g;
                int sy = dy / g;

                int id = sx * points[i][1] - sy * points[i][0]; // (yi-y)/(xi-x) = sy/sx
                int key1 = (sx << 12) | (sy + 2000);            // make hash key
                int key2 = (dx << 12) | (dy + 2000);

                t[key1][id]++;                  // 算所有梯形
                v[key2][id]++;                  // 算平行四邊形
            }
        }
        return count(t) - count(v) / 2;
    }
};