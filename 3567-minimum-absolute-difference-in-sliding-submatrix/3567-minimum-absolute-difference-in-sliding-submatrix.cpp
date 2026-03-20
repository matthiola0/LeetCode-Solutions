class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                set<int> vals;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        vals.insert(grid[x][y]);
                    }
                }

                if (vals.size() < 2) {}
                else {
                    int min_diff = INT_MAX;
                    auto it = vals.begin();
                    int prev = *it;
                    ++it;

                    while (it != vals.end()) {
                        min_diff = min(min_diff, *it - prev);
                        prev = *it;
                        ++it;
                    }
                    ans[i][j] = min_diff;
                }
            }
        }
        return ans;
    }
};