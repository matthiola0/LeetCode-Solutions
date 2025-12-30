class Solution {
private:
    int dir[3][3][2] = {{{-1, -1}, {-1, 0}, {-1, 1}}, 
                        {{0, -1}, {0, 0}, {0, 1}}, 
                        {{1, -1}, {1, 0}, {1, 1}}};
    bool check(vector<vector<int>>& grid, int r, int c) {
        vector<bool> dict(10);
        int rowSum[3] = {0}, colSum[3] = {0};
        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int nr = r + dir[i][j][0];
                int nc = c + dir[i][j][1];
                int val = grid[nr][nc];

                if (val < 1 || val > 9) return false;
                if (dict[val]) return false;
                dict[val] = true;
                rowSum[i] += val;
                colSum[j] += val;

                if (i == j) diag1 += val;
                if (i + j == 2) diag2 += val;
            }
        }

        for(int k=0; k<3; ++k) {
            if(rowSum[k] != 15 || colSum[k] != 15) return false;
        }
        if (diag1 != 15 || diag2 != 15) return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        if (row < 3 || col < 3) return 0;
        int res = 0;
        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (check(grid, i, j))
                    res++;
            }
        }
        return res;
    }
};