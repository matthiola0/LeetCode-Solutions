class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        
        vector<vector<int>> p(n, vector<int>(m, 1));
        
        long long pref = 1; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = pref;
                pref = (pref * grid[i][j]) % mod;
            }
        }
        
        long long suff = 1; 
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = (p[i][j] * suff) % mod;
                suff = (suff * grid[i][j]) % mod;
            }
        }
        
        return p;
    }
};