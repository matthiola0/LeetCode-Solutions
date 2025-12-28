class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = INT_MAX;
        int ans;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (1LL * mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};