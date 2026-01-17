class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (auto& w : words) {
            reverse(w.begin(), w.end());
        }

        sort(words.begin(), words.end());

        int totalLength = 0;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && words[i+1].find(words[i]) == 0) {
                continue;
            }
            
            totalLength += words[i].length() + 1;
        }

        return totalLength;
    }
};