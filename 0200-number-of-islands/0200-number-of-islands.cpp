class Solution {
private:
	int m, n;
	void dfs(vector<vector<char>>& grid, int x, int y) {
		if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') return;
		grid[x][y] = '0';
		dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        dfs(grid, x, y - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};

