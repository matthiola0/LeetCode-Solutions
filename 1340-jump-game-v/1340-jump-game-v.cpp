class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 0); 
        int res = 0;

        for (int i = 0; i < n; i++) {
            res = max(res, dfs(arr, d, i, dp));
        }

        return res;
    }

private:
    int dfs(vector<int>& arr, int d, int i, vector<int>& dp) {
        if (dp[i] != 0) return dp[i];

        int n = arr.size();
        int max_jumps = 1;

        for (int k = 1; k <= d; k++) {
            if (i + k >= n) break;
            if (arr[i + k] >= arr[i]) break;
            
            max_jumps = max(max_jumps, 1 + dfs(arr, d, i + k, dp));
        }

        for (int k = 1; k <= d; k++) {
            if (i - k < 0) break;
            if (arr[i - k] >= arr[i]) break;
            
            max_jumps = max(max_jumps, 1 + dfs(arr, d, i - k, dp));
        }

        return dp[i] = max_jumps;
    }
};