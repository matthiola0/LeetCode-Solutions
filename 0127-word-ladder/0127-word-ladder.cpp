class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> exist(wordList.begin(), wordList.end());
        unordered_map<string, unordered_map<string, bool>> mp;
        if (exist.find(endWord) == exist.end()) return 0;

        // build edge
        string tmp;
        for (int i = 0; i < beginWord.size(); i++) {    // begin word
            string tmp = beginWord;
            for (int j = 0; j < 26; j++) {          
                if ('a' + j != beginWord[i]) {
                    tmp[i] = 'a' + j;
                    if (exist.find(tmp) != exist.end()) {
                        mp[beginWord][tmp] = true;
                    }
                }
            }
        }
        for (string s : wordList) {                     // other
            string tmp;
            for (int i = 0; i < s.size(); i++) {
                tmp = s;
                for (int j = 0; j < 26; j++) {
                    if ('a' + j != s[i]) {
                        tmp[i] = 'a' + j;
                        if (exist.find(tmp) != exist.end()) {
                            mp[s][tmp] = true;
                        }
                    }
                }
            }
        }
        
        int ans = 1;
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string cur = q.front();
                q.pop();
                for (auto next : mp[cur]) {
                    if (next.first == endWord) {
                        return ans + 1;
                    }
                    if (visited.find(next.first) == visited.end()) {
                        q.push(next.first);
                        visited.insert(next.first);
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};