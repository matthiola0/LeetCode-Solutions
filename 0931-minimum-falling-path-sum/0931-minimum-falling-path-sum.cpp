class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp0(matrix[0].begin(), matrix[0].end()), dp1(n);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) 
                    dp1[j] = min(dp0[j], dp0[j+1]) + matrix[i][j];
                else if (j == n - 1)
                    dp1[j] = min(dp0[j], dp0[j-1]) + matrix[i][j];
                else 
                    dp1[j] = min(min(dp0[j], dp0[j-1]), dp0[j+1]) + matrix[i][j];
            }
            dp0 = dp1;
        }

        int minVal = INT_MAX;
        for (int i = 0; i < n; i++) {
            minVal = min(minVal, dp0[i]);
        }

        return minVal;
    }
};