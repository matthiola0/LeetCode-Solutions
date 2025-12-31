class Solution {
private:
    bool canWalk(int row, int col, vector<vector<int>>& cells, int day) {
        vector<int> grid(row * col, 0); 
        
        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r * col + c] = 1;
        }

        queue<pair<int, int>> q;
        for (int j = 0; j < col; j++) {
            if (grid[0 * col + j] == 0) {
                q.push({0, j});
                grid[0 * col + j] = 2;
            }
        }

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == row - 1) return true;
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col) {
                    if (grid[nr * col + nc] == 0) {
                        grid[nr * col + nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0, r = row * col;
        int ans = 0;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (canWalk(row, col, cells, m)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};