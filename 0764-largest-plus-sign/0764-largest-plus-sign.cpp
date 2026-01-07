class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        vector<vector<int>> val(n, vector<int>(n, n));
        for (auto i: mines) {
            grid[i[0]][i[1]] = 0;
        }

        for (int i = 0; i < n; i++) {
            int preR = 0, preC = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) preR = 0;
                else preR++;

                if (grid[j][i] == 0) preC = 0;
                else preC++;

                val[i][j] = min(preR, val[i][j]);
                val[j][i] = min(preC, val[j][i]);
            }

            int sufR = 0, sufC = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) sufR = 0;
                else sufR++;

                if (grid[j][i] == 0) sufC = 0;
                else sufC++;

                val[i][j] = min(sufR, val[i][j]);
                val[j][i] = min(sufC, val[j][i]);
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, val[i][j]);
            }
        }

        return res;
    }
};