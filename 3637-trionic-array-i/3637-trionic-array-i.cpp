class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int cnt = 0, dir = 1;
        if (nums[1] < nums[0]) return false;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) return false;
            if (dir == 1 && nums[i] < nums[i-1]) {
                cnt++;
                dir *= -1;
                if (cnt >= 3) return false;
            } else if (dir == -1 && nums[i] > nums[i-1]) {
                cnt++;
                dir *= -1;
                if (cnt >= 3) return false;
            }
        }
        return cnt == 2;
    }
};