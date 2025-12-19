class Solution {
private:
    int expand(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            int odd = expand(s, i, i);
            int even = expand(s, i, i+1);
            int max_len = max(odd, even);

            if (max_len > end - start + 1) {
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};