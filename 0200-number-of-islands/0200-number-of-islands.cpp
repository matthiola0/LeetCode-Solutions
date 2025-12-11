class Solution {
private:
    int m, n;
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || grid[x][y] == '0') return;
        visited[x][y] = true;
        grid[x][y] = '0';
        bfs(grid, visited, x + 1, y);
        bfs(grid, visited, x, y + 1);
        bfs(grid, visited, x - 1, y);
        bfs(grid, visited, x, y - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(grid, visited, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};