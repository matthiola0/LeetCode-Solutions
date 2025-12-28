class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        set<int> modify_row, modify_col;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    modify_row.insert(i);
                    modify_col.insert(j);
                }
            }
        }

        for (auto i : modify_row) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
        for (auto j : modify_col) {
            for (int i = 0; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }
};