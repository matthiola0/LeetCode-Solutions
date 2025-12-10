class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (char c : t) map[c]++;
        int count = t.size();
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int head = 0;
        while (right < s.size()) {
            if (map[s[right]] > 0) {
                count--;
            }
            map[s[right]]--;
            right++;

            while (count == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    head = left;
                }
                if (map[s[left]] == 0) {
                    count++;
                }
                map[s[left]]++;
                left++;
            }   
        }
        return minLen == INT_MAX ? "" : s.substr(head, minLen);

    }
};