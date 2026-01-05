class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minVal = INT_MAX;
        int cnt = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int val = matrix[i][j];
                if (val < 0) {
                    cnt++;
                    val *= -1;
                }

                sum += val;
                minVal = min(minVal, val);
            }
        }
        if (cnt % 2 == 0) return sum;
        return sum - 2 * minVal;
    }
};