class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        queue<string> q;
        int num = 0;
        vector<string> res;
        for (const string &w : words) {
            if (q.empty()) {
                num += w.size();
                q.push(w);
            } else if (num + 1 + w.size() > maxWidth) {
                string s = q.front();
                q.pop();
                int space = maxWidth - num;
                int hole = q.size();
                if (hole != 0) {
                    int mul = hole == 0 ? 0 : space/hole;
                    int extra = space % hole;
                    while (!q.empty()) {
                        s.append(1 + mul + (extra > 0 ? 1 : 0), ' ');
                        extra--;
                        s += q.front();
                        q.pop();
                    }
                } else {
                    s.append(maxWidth - s.size(), ' ');
                }
                res.push_back(s);

                q.push(w);
                num = w.size();
            } else {
                num += 1 + w.size();
                q.push(w);
            }
        }
        string s = q.front();
        q.pop();
        while (!q.empty()) {
            s += " " + q.front();
            q.pop();
        }
        s.append(maxWidth - s.size(), ' ');
        res.push_back(s);
        return res;
    }
};