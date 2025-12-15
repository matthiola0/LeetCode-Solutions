class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = INT_MAX;
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            smallest = min(smallest, prices[i]);
            res = max(res, prices[i] - smallest);
        }
        return res;
    }
};