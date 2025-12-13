class Solution {
private:
	int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	bool check(vector<vector<int>>& grid, int x, int y, int m, int n) {
	    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) return false;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
	    int m = grid.size(), n = grid[0].size();
    	int ans = -1;
        int fresh = 0;
	    queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) 
                    q.push({i, j});
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        if (fresh == 0) return 0;
        while (!q.empty()) {
            int t = q.size();
            ans++;
            while(t--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    if (check(grid, x + dir[i][0], y + dir[i][1], m, n)) {
                        grid[x + dir[i][0]][y + dir[i][1]] = 2;
                        q.push({x + dir[i][0], y + dir[i][1]});
                        fresh--;
                    }
                }
            }
        }
        if (fresh != 0) return -1;
        else return ans;
    }
};
