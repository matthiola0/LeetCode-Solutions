class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lower_last(26, -1), upper_first(26, n);
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (islower(c)) {
                lower_last[c - 'a'] = max(lower_last[c - 'a'], i);
            } else {
                upper_first[c - 'A'] = min(upper_first[c - 'A'], i);
            }
        }

        for (int i = 0; i < 26; i++) {
            if (lower_last[i] != -1 && upper_first[i] != n && lower_last[i] < upper_first[i])
                res++;
        }
        return res;
    }
};