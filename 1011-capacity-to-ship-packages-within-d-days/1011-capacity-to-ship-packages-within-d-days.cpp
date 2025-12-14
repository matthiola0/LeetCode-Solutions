class Solution {
private:
    bool check(vector<int>& weights, int days, int max_weight) {
        int need_day = 1;
        int cur_weight = 0;
        for (int i : weights) {
            cur_weight += i;
            if (cur_weight > max_weight) {
                need_day++;
                cur_weight = i;
            }
        }
        return need_day <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for (int w : weights) {l = max(l, w); r += w;}
        while (l < r) {
            int m = l + (r - l) / 2;
            if (check(weights, days, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};