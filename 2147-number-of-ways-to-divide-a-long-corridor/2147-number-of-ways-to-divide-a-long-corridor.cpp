class Solution {
public:
    int numberOfWays(string corridor) {
        int seat = 0;
        for (char &c : corridor) {
            if (c == 'S') seat++;
        }
        if (seat % 2 || seat == 0) return 0;
        int divider = seat / 2 - 1;
        int ans = 1, mod = 1e9 + 7;
        int cur_seat = 0, count = 1;
        for (char &c : corridor) {
            if (divider == 0) break;
            if (cur_seat == 2) {
                if (c == 'S') {
                    divider--;
                    ans = 1LL * ans * count % mod;
                    count = 1;
                    cur_seat = 1;
                } else {
                    count++;
                }
            } else {
                if (c == 'S') {
                    cur_seat++;
                }
            }
        }
        return ans;
    }
};