class Solution {
private:
    int mod = 1e9 + 7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, int> freq;
        for (auto p : points) {
            freq[p[1]]++;
        }
        long long sum = 0, square_sum = 0;
        for (auto [y, f]: freq) {
            if (f <= 1) continue;
            long long cf_2 = 1LL* f * (f - 1) / 2;
            sum += cf_2;
            square_sum += (cf_2 * cf_2) % mod;
        }
        long long ans = (sum * sum - square_sum) / 2 % mod;
        return ans;
    }
};