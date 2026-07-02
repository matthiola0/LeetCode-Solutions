class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> min_damage(m, vector<int>(n, INT_MAX));
        min_damage[0][0] = grid[0][0];

        queue<array<int, 3>> q;
        q.push({0, 0, grid[0][0]});
        
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty()) {
            auto [r, c, damage] = q.front();
            q.pop();

            if (damage >= health) continue;
            if (r == m-1 && c == n-1) return true;

            for (auto& d: dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= m || nr < 0 || nc >= n || nc < 0) continue;

                int next_damage = damage + grid[nr][nc];
                if (next_damage < min_damage[nr][nc]) {
                    min_damage[nr][nc] = next_damage;
                    q.push({nr, nc, next_damage});
                }
            }
        }
        return false;
    }
};