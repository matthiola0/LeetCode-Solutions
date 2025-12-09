class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        vector<int> left(n), right(n);
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            if (height[i] > left[i-1]) {
                left[i] = height[i];
            } else {
                left[i] = left[i-1];
            }
        }
        right[n-1] = height[n-1];
        for (int i = n - 2; i >= 0; i--) {
            if (height[i] > right[i+1]) {
                right[i] = height[i];
            } else {
                right[i] = right[i+1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (height[i] < min(left[i], right[i])) {
                ans += min(left[i], right[i]) - height[i];
            }
        }
        return ans;
    }
};