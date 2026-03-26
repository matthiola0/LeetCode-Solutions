class Solution {
    struct PosInfo {
        int min_r = 1e9, max_r = -1;
        int min_c = 1e9, max_c = -1;
    };

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long long>> v(m + 1, vector<long long>(n + 1, 0));
        unordered_map<long long, PosInfo> hash;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long val = grid[i][j];
                hash[val].min_r = min(hash[val].min_r, i);
                hash[val].max_r = max(hash[val].max_r, i);
                hash[val].min_c = min(hash[val].min_c, j);
                hash[val].max_c = max(hash[val].max_c, j);
                v[i + 1][j + 1] = v[i][j + 1] + v[i + 1][j] - v[i][j] + val;
            }
        }

        // Helper function to check if removing 'diff' keeps the section connected
        auto canRemove = [&](long long diff, int r1, int r2, int c1, int c2) {
            // 1. If it's a 1D horizontal strip, only the left/right ends are valid
            if (r1 == r2) return grid[r1][c1] == diff || grid[r1][c2] == diff;
            
            // 2. If it's a 1D vertical strip, only the top/bottom ends are valid
            if (c1 == c2) return grid[r1][c1] == diff || grid[r2][c1] == diff;
            
            // 3. If it's a 2D block (>= 2x2), ANY cell can be removed
            if (!hash.count(diff)) return false;
            
            if (r1 == 0 && c1 == 0 && c2 == n - 1) return hash[diff].min_r <= r2; // Top
            if (r2 == m - 1 && c1 == 0 && c2 == n - 1) return hash[diff].max_r >= r1; // Bottom
            if (r1 == 0 && r2 == m - 1 && c1 == 0) return hash[diff].min_c <= c2; // Left
            if (r1 == 0 && r2 == m - 1 && c2 == n - 1) return hash[diff].max_c >= c1; // Right
            
            return false;
        };

        // Check Horizontal Cuts (starting from 1 to ensure both sections are non-empty)
        for (int i = 1; i < m; i++) {
            long long top_sum = v[i][n];
            long long bot_sum = v[m][n] - v[i][n];

            if (top_sum == bot_sum) return true;

            if (bot_sum > top_sum) {
                if (canRemove(bot_sum - top_sum, i, m - 1, 0, n - 1)) return true;
            } else {
                if (canRemove(top_sum - bot_sum, 0, i - 1, 0, n - 1)) return true;
            }
        }

        // Check Vertical Cuts (starting from 1)
        for (int j = 1; j < n; j++) {
            long long left_sum = v[m][j];
            long long right_sum = v[m][n] - v[m][j];

            if (left_sum == right_sum) return true;

            if (right_sum > left_sum) {
                if (canRemove(right_sum - left_sum, 0, m - 1, j, n - 1)) return true;
            } else {
                if (canRemove(left_sum - right_sum, 0, m - 1, 0, j - 1)) return true;
            }
        }

        return false;
    }
};