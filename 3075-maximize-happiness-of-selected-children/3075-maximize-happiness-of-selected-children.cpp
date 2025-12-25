class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        int pick = 0;
        long long res = 0;
        for (int i = 0; i < k; i++) {
            if (happiness[i] - pick > 0) {
                res += happiness[i] - pick;
                pick++;
            } else {
                break;
            }
        }
        return res;
    }
};