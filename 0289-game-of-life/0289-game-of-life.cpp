class Solution {
private:
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, 
                    {0, -1}, {0, 1},
                    {1, -1}, {1, 0}, {1, 1}};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int neighbor = 0;

                for (int k = 0; k < 8; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x >= 0 && x < m && y >= 0 && y < n && 
                        (board[x][y] == 1 || board[x][y] == 2)) 
                        neighbor++;
                }
                if (board[i][j] == 1 && (neighbor < 2 || neighbor > 3)) 
                    board[i][j] = 2;
                else if (board[i][j] == 0 && neighbor == 3)
                    board[i][j] = 3;
                
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] %= 2;
            }
        }
        return;
    }
};