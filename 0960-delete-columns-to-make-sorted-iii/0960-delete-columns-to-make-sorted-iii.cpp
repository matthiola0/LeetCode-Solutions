class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        vector<int> dp(m, 1);
        int max_kept = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                bool flag = true;
                for (int r = 0; r < n; ++r) {
                    if (strs[r][j] > strs[r][i]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_kept = max(max_kept, dp[i]);
        }
        return m - max_kept;
    }
};