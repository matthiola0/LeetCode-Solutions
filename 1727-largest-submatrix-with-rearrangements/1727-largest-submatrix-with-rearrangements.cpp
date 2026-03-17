class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1 && i != 0) {
                    matrix[i][j] = matrix[i-1][j] + 1;
                }
            }

            vector<int> curr = matrix[i];
            sort(curr.rbegin(), curr.rend());

            for (int j = 0; j < n; j++) {
                ans = max(ans, curr[j] * (j + 1));
            }
        }
        
        return ans;
    }
};