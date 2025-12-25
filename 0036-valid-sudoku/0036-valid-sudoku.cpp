class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false}, cols[9][9] = {false}, subboxes[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '1';
                if (rows[i][cur] || cols[j][cur] || subboxes[(i / 3) * 3 + (j / 3)][cur])
                    return false;
                rows[i][cur] = cols[j][cur] = subboxes[(i / 3) * 3 + (j / 3)][cur] = true;
            }
        }
        return true;
    }
};