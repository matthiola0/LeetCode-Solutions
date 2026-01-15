class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = 2, v = 2;
        int cur = 2;
        if (hBars.size() == 0 || vBars.size() == 0) return 1;

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i-1] == 1) {
                cur++;
                h = max(h, cur);
            } else {
                cur = 2;
            }
        }
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i-1] == 1) {
                cur++;
                v = max(v, cur);
            } else {
                cur = 2;
            }
        }
        int a = min(h, v);

        return a * a;
    }
};