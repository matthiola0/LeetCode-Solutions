class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0;
        int minStart = 0, minLen = INT_MAX;
        int counter = t.size();
        unordered_map<char, int> need;
        for (char c : t) need[c]++;
        while (end < s.size()) {
            char c1 = s[end];
            if (need[c1] > 0) counter--;
            need[c1]--;
            end++;
            
            while (counter == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                char c2 = s[start];
                need[c2]++;
                if (need[c2] > 0) counter++;
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};