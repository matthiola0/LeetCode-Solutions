class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    	unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        
        int ans = 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            int t = q.size();
            ans++;
            while(t--) {
                string s = q.front();
                q.pop();

                string tmp_s = s;
                for (int i = 0; i < tmp_s.size(); i++) {
                    char tmp_c = tmp_s[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (tmp_c == c) continue;
                        tmp_s[i] = c;
                        if (words.count(tmp_s)) {
                            if (tmp_s == endWord) return ans + 1;
                            words.erase(tmp_s);
                            q.push(tmp_s);
                        }
                    }
                    tmp_s[i] = tmp_c;
                }
            }
        }
        return 0;
    }
};

