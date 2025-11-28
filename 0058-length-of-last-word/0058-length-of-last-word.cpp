class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0, last = s.size() - 1, start;
        while (last >= 0 && s[last] == ' ') {
            last--;
        }
        start = last;
        while (start >=0 && s[start] != ' ') {
            start--;
        }
        return last - start;
    }
};