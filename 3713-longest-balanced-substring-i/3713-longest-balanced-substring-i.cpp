class Solution {
private:
    bool isBalanced(vector<int>& fre) {
        int tar = -1;
        for (auto i : fre) {
            if (i > 0) {
                if (tar == -1) {
                    tar = i;
                } else if (i != tar) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int longestBalanced(string s) {
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; i ++) {
            vector<int> fre(26, 0);
            for (int j = i; j < n; j++) {
                fre[s[j] - 'a']++;
                int cur_len = j - i + 1;
                if (isBalanced(fre)) {
                    res = max(res, cur_len);
                }
            }
        }
        return res;
    }
};