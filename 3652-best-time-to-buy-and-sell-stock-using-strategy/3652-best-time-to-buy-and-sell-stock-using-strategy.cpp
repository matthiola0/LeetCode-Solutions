class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long original = 0;
        long long cur_max = LLONG_MIN, cur = 0;
        for (int i = 0 ; i < k/2; i++) {
            original += prices[i] * strategy[i];
        }
        for (int i = k/2 ; i < k; i++) {
            original += prices[i] * strategy[i];
            cur += prices[i];
        }
        for (int i = k; i < prices.size(); i++) {
            original += prices[i] * strategy[i];
            cur += prices[i] * strategy[i];
        }
        cur_max = max(cur_max, max(original, cur));
        for (int i = k; i < prices.size(); i++) {
            cur -= prices[i] * strategy[i];
            cur += prices[i];
            cur -= prices[i - k/2];
            cur += prices[i - k] * strategy[i - k];
            cur_max = max(cur_max, cur);
        }
        return cur_max;
    }
};