class Solution {
public:
    long long count(long long tar, vector<int>& coins) {
        long long res = 0;
        int n = coins.size();

        for (int mask = 1; mask < (1 << n); mask++) {
            long long cur_lcm = 1;
            int bits = __builtin_popcount(mask);

            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    cur_lcm = lcm(cur_lcm, (long long)coins[i]);
                    if (cur_lcm > tar) break;
                }
            }

            if (cur_lcm > tar) continue;

            if (bits % 2 == 1) res += (tar/cur_lcm);
            else res -= (tar/cur_lcm);
        }

        return res;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long l = 1, r = 50LL * 1e9;
        long long ans = 1;
        while (l <= r) {
            long long m = (l + r) / 2;
            if (count(m, coins) >= k) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};