class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({position[i], (double)(target-position[i])/speed[i]});
        }

        sort(v.rbegin(), v.rend());

        int ans = 0;
        double curMax = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].second > curMax) {
                curMax = v[i].second;
                ans++;
            }
        }
        return ans;
    }
};