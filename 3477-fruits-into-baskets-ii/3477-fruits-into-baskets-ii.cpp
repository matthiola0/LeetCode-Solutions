class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = fruits.size();
        for (int fruit: fruits) {
            for (int &basket: baskets) {
                if (basket >= fruit) {
                    res--;
                    basket = 0;
                    break;
                }
            }
        }
        return res;
    }
};