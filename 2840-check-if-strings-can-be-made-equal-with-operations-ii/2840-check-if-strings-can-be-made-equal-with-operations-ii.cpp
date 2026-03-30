class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        unordered_map<char, int> hash0, hash1;
        for (int i = 0; i < s1.size(); i += 2) {
            hash0[s1[i]]++;
            hash0[s2[i]]--;
        }
        for (int i = 1; i < s1.size(); i += 2) {
            hash1[s1[i]]++;
            hash1[s2[i]]--;
        }

        for (auto x: hash0) {
            if (x.second != 0) return false;
        }
        for (auto x: hash1) {
            if (x.second != 0) return false;
        }

        return true;
    }
};