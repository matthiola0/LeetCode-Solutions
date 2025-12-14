class Solution {
private:
    bool check(vector<int>& piles, int h, int k) {
        for (int p : piles) {
            h -= ((p - 1) / k + 1);
        }
        if (h >= 0) return true;
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;
        for (int p : piles) r = max(r, p);

        while (l < r) {
            int m = l + (r - l) / 2;
            if (check(piles, h, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};