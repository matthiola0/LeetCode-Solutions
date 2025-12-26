class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = count(customers.begin(), customers.end(), 'Y');
        int res = 0, cur_min = penalty;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') penalty--;
            if (customers[i] == 'N') penalty++;

            if (penalty < cur_min) {
                cur_min = penalty;
                res = i + 1;
            }
        }
        return res;
    }
};