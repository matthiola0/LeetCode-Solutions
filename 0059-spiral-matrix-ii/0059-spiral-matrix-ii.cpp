class Solution {
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int cur[] = {0, -1};
        int d = 0;
        for (int i = 1; i <= n * n; i++) {
            int next_r = cur[0] + dir[d][0];
            int next_c = cur[1] + dir[d][1];
            if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n || mat[next_r][next_c] != 0) {
                d = (d + 1) % 4;
                next_r = cur[0] + dir[d][0];
                next_c = cur[1] + dir[d][1];
            }
            cur[0] = next_r;
            cur[1] = next_c;
            mat[cur[0]][cur[1]] = i;
        }
        return mat;
    }
};