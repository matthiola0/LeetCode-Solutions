class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<pair<char, int>> count(26);
        for (int i = 0; i < 26; i++) {
            count[i].first = 'a' + i;
            count[i].second = 0;
        }

        for (char c: s) {
            count[c - 'a'].second++;
        }

        sort(count.begin(), count.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        if (count[0].second > (n + 1) / 2)
            return "";

        int idx = 0;
        string res(n, ' ');
        for (int i = 0; i < 26; i++) {
            int j = count[i].second;
            while (j--) {
                if (idx >= n) {
                    idx = 1;
                }
                res[idx] = count[i].first;
                idx += 2;
            }
        }

        return res;
    }
};