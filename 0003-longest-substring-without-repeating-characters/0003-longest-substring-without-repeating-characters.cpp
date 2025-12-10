class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        vector<int> dict(128, -1);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (dict[c] != -1 && dict[c] >= left) {
                left = dict[c] + 1;
            }
            dict[c] = i;
            
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};