class Solution {
private:
    int mod = 1e9 + 7;
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> prevP, prevN;
        int n = nums.size();
        for (int num : nums) {
            prevN[num]++;
        }

        int ans = 0;
        for (int num : nums) {
            prevN[num]--;
            ans = (ans + (1LL * prevP[num * 2] * prevN[num * 2]) % mod) % mod;
            prevP[num]++;
        }
        return ans;
    }
};