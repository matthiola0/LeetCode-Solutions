class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<pair<int, int>> buckets[26];
        int ans = 0;

        for (int i = 0; i < words.size(); i++) {
            char c = words[i][0];
            buckets[c - 'a'].push_back({i, 0});
        }

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            vector<pair<int, int>> oldBucket = buckets[c - 'a'];
            buckets[c - 'a'].clear();
            
            for (auto &[idx, progress]: oldBucket) {
                progress++;

                if (progress == words[idx].size()) ans++;
                else {
                    char nextC = words[idx][progress];
                    buckets[nextC - 'a'].push_back({idx, progress});
                }
            }
        }

        return ans;
    }
};