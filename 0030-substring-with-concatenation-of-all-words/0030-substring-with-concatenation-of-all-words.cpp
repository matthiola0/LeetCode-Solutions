class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), m = words.size();
        int wordLen = words[0].size();

        unordered_map<string, int> originalCount;
        for (const string& w: words) {
            originalCount[w]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i;
            unordered_map<string, int> currentCount;
            
            int count = 0;
            while (right + wordLen <= n) {
                string w = s.substr(right, wordLen);
                right += wordLen;

                if (originalCount.count(w)) {
                    currentCount[w]++;
                    count++;

                    while (currentCount[w] > originalCount[w]) {
                        currentCount[s.substr(left, wordLen)]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == m) {
                        res.push_back(left);
                    }
                } else {
                    currentCount.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return res;
    }
};