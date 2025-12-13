class Solution {
private:
	int m, n;
	bool found;
	void dfs(vector<vector<char>>& board, string word, int cur, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[cur]) return;
        if (cur == word.size() - 1) {
            found = true;
            return;
        }
        char tmp = board[x][y];
        board[x][y] = 0;
        dfs(board, word, cur+1, x + 1, y);
        dfs(board, word, cur+1, x, y + 1);
        dfs(board, word, cur+1, x - 1, y);
        dfs(board, word, cur+1, x, y - 1);
        board[x][y] = tmp;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
    	found = false;
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (found == true) return true;
                dfs(board, word, 0, i, j);
            }
        }
        return found;
    }
};

