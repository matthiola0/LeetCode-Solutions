class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int r = rStart, c = cStart;
        
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        
        int dir = 0;
        int step = 1;
        
        res.push_back({r, c});
        
        while (res.size() < rows * cols) {
            for (int k = 0; k < 2; ++k) {
                for (int i = 0; i < step; ++i) {
                    r += dr[dir];
                    c += dc[dir];
                    
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        res.push_back({r, c});
                    }
                }
                dir = (dir + 1) % 4;
            }
            step++;
        }
        
        return res;
    }
};