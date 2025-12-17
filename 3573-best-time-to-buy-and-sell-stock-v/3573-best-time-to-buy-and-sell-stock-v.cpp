class Solution {
private:
    struct Data {
        long long profit, buy, sell;
        Data (): profit(0), buy(0), sell(0) {}
        Data (long long p, long long b, long long s): profit(p), buy(b), sell(s) {}
    };
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        int x0 = prices[0];
        vector<vector<Data>> dp(n, vector<Data>(k+1));
        for (int t = 0; t <= k; t++) {
            dp[0][t] = Data(0, -x0, x0);
        }
        for (int d = 1; d < n; d++) {
            int x = prices[d];
            for (int t = 1; t <= k; t++) {
                auto [p, b, s] = dp[d-1][t];
                long long prevP = dp[d-1][t-1].profit;
                p = max(p, max(b+x, s-x));
                b = max(b, prevP - x);
                s = max(s, prevP + x);
                dp[d][t] = Data(p, b, s);
            }
        }
        return dp[n-1][k].profit;
    }
};