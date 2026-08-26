class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones_count = 0;
        string res = "";
        
        for (int right = 0; right < s.length(); right++) {
            if (s[right] == '1') {
                ones_count++;
            }
            
            while (ones_count == k) {
                int len = right - left + 1;
                string cur = s.substr(left, len);
                
                if (res == "") {
                    res = cur;
                } else if (cur.length() < res.length()) {
                    res = cur;
                } else if (cur.length() == res.length() && cur < res) {
                    res = cur;
                }
                
                if (s[left] == '1') {
                    ones_count--;
                }
                left++;
            }
        }
        
        return res;
    }
};