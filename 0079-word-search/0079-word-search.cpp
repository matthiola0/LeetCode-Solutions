class Solution {
private:
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int cur) {
        if (cur == word.size()) return true;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[cur]) 
            return false;

        char tmp = board[x][y];
        board[x][y] = '0';
        bool found = dfs(board, word, x + 1, y, cur + 1) ||
                     dfs(board, word, x, y + 1, cur + 1) ||
                     dfs(board, word, x - 1, y, cur + 1) ||
                     dfs(board, word, x, y - 1, cur + 1);
                    
        board[x][y] = tmp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};