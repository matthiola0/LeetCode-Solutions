class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        if (dict.count(beginWord)) dict.erase(beginWord);

        int ans = 0;
        while(!q.empty()) {
            int t = q.size();
            ans++;
            while(t--) {
                string s = q.front();
                q.pop();
                if (s == endWord) return ans;

                string tmp = s;
                for (int i = 0; i < tmp.size(); i++) {
                    char origin = tmp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == origin) continue;
                        tmp[i] = c;
                        if (dict.count(tmp)) {
                            q.push(tmp);
                            dict.erase(tmp);
                        }
                    }
                    tmp[i] = origin;
                }
            }
        }
        return 0;
    }
};