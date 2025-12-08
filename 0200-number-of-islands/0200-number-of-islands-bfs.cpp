class Solution {
private:      
    int m, n;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void bfs(vector<vector<char>>& grid, pair<int, int> first) {
        grid[first.first][first.second] = '2';  // visited
        queue<pair<int, int>> q;
        q.push(first);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int next_x = cur.first + dir[i].first,
                    next_y = cur.second + dir[i].second;
                if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) {
                    continue;
                }
                if (grid[next_x][next_y] == '1') {
                    q.push({next_x, next_y});
                    grid[next_x][next_y] = '2';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, {i, j});
                    res++;
                }
            }
        }
        return res;
    }
};

