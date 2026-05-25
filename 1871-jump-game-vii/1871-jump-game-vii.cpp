class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        if (s[n - 1] == '1')  return false;

        vector<bool> dp(n, false);
        dp[0] = true;

        int active_jump = 0; 
        for (int i = 1; i < n; ++i) {
            if (i - minJump >= 0 && dp[i - minJump]) {
                active_jump++;
            }

            if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) {
                active_jump--;
            }

            if (s[i] == '0' && active_jump > 0) {
                dp[i] = true;
            }
        }
        
        return dp[n - 1];
    }
};