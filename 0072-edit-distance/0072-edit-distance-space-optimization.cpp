class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp1(m+1);
        vector<int> dp2(m+1);
        for (int j = 0; j <= m; j++) {
            dp1[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            dp2[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] != word2[j-1]) {
                    dp2[j] = min(dp1[j-1], min(dp1[j], dp2[j-1])) + 1;
                } else {
                    dp2[j] = dp1[j-1];
                }
            }
            dp1 = dp2;
        }
        return dp1[m];
    }
};