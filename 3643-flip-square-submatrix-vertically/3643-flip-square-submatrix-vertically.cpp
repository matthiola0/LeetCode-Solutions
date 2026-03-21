class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < k/2; i++) {
            for (int j = y; j < y + k; j++) {
                int tmp = grid[x + i][j];
                grid[x + i][j] = grid[x + k - 1 - i][j];
                grid[x + k - 1 - i][j] = tmp;
            }
        }
        return grid;
    }
};