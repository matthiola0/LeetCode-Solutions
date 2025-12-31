class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char_to_word;
        unordered_map<string, char> word_to_char;

        stringstream ss(s);
        string cur;
        for (char c: pattern) {
            if (!(ss >> cur)) return false;

            if (char_to_word.count(c) && char_to_word[c] != cur) 
                return false;
            if (word_to_char.count(cur) && word_to_char[cur] != c)
                return false;

            char_to_word[c] = cur;
            word_to_char[cur] = c;
        }
        if (ss >> cur) return false;
        return true;
    }
};