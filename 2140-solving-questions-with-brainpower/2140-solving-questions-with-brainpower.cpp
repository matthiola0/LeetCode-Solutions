class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1);
        
        for (int i = 0; i < n; i++) {
            dp[i+1] = max(dp[i+1], dp[i]);
            
            int idx = i + questions[i][1] + 1;
            if (idx < n) {
                dp[idx] = max(dp[idx], dp[i] + questions[i][0]);
            } else {
                dp[n] =  max(dp[n], dp[i] + questions[i][0]);
            }
        }
        return dp[n];
    }
};