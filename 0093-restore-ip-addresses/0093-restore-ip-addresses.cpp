class Solution {
private:
    bool valid(string s) {
        if(s.size() > 3) return false;
        if (s.size() > 1 && s[0] == '0') return false;
        if (stoi(s) >  255) return false;
        return true;
    }
    void backtrack(const string& s, vector<string>& res, vector<string>& seg, int start) {
        if (seg.size() == 4 && start == s.size()) {
            res.push_back(seg[0] + '.' + seg[1] + '.' + seg[2] + '.' + seg[3]);
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (start + i > s.size()) break;
            string sub = s.substr(start, i);
            if (valid(sub) && seg.size() < 4) {
                seg.push_back(sub);
                backtrack(s, res, seg, start + i);
                seg.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return {};
        vector<string> res;
        vector<string> seg;
        backtrack(s, res, seg, 0);
        return res;
    }
};