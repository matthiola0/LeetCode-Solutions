class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (int i = 0; i < s.size(); i++) {
            if (!mp1.count(s[i])) mp1[s[i]] = i;
            if (!mp2.count(t[i])) mp2[t[i]] = i;
            
            if (mp1[s[i]] != mp2[t[i]]) return false;
        }
        return true;
    }
};