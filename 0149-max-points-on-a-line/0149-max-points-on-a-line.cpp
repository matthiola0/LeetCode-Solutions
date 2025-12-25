class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        int n = points.size();
        for (int i = 0; i < n - 1; i++) {
            unordered_map<double, int> mp;
            for (int j = i + 1; j < n; j++) {
                double slope = (double)(points[j][1] - points[i][1])/
                               (double)(points[j][0] - points[i][0]);
                if (points[j][0] - points[i][0] == 0)   //inf
                    mp[abs(slope)]++;
                else
                    mp[slope]++;
            }
            int tmp = 0;
            for (auto it: mp) {
                tmp = max(tmp, it.second);
            }
            res = max(res, tmp + 1);
        }
        return res;
    }
};