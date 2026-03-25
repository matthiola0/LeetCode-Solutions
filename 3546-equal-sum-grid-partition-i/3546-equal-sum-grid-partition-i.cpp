class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long long>> v(m + 1, vector<long long>(n + 1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v[i + 1][j + 1] = v[i][j + 1] + v[i + 1][j] - v[i][j] + grid[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            if (v[m][n] == 2 * v[i][n])
                return true;
        }
        for (int j = 0; j < n; j++) {
            if (v[m][n] == 2 * v[m][j])
                return true;
        }

        return false;
    }
};