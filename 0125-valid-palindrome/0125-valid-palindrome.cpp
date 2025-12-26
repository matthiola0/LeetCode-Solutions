class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        bool palindrome = true;
        while (i < j) {
            while (i < j && !isalpha(s[i])) i++;
            while (i < j && !isalpha(s[j])) j--;
            if (i >= j) break;

            int a, b;
            if (s[i] >= 'a') a = s[i] - 'a';
            else a = s[i] - 'A';
            if (s[j] >= 'a') b = s[j] - 'a';
            else b = s[j] - 'A';

            if (a != b) {
                palindrome = false;
                break;
            }
            i++; j--;
        }
        return palindrome;
    }   
};