class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (j == 0) {
                    triangle[i][0] += triangle[i-1][0];
                } else {
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
            }
            triangle[i][i] += triangle[i-1][i-1];
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, triangle[n-1][i]);
        }
        return res;
    }
};