class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        int j = n;
        for (int i = 0; i < m; i++) {
            while (j > 0 && grid[i][j-1] < 0) {
                j--;
            }
            res += (n-j);
        }
        return res;
    }
};