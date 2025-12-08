class Solution {
private:      
    int m, n;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, pair<int, int> cur) {
        grid[cur.first][cur.second] = '2';  // visited
        for (int i = 0; i < 4; i++) {
            int next_x = cur.first + dir[i].first, 
                next_y = cur.second + dir[i].second;
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) {
                continue;
            }
            if (grid[next_x][next_y] == '1') {
                dfs(grid, {next_x, next_y});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<pair<int, int>> ones;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, {i, j});
                    res++;
                }
            }
        }
        return res;
    }
};