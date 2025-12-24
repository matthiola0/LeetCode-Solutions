class Solution {
private:
    char gene[4] = {'A', 'C', 'G', 'T'};
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valid;
        valid.insert(startGene);
        unordered_map<string, vector<string>> dict;
        for (string& s: bank) {
            valid.insert(s);
            string cur = s;
            for (int i = 0; i < cur.size(); i++) {
                char c = cur[i];
                for (int j = 0; j < 4; j++) {
                    if (c == gene[j]) continue;
                    cur[i] = gene[j];
                    if (valid.count(cur)) {
                        dict[s].push_back(cur);
                        dict[cur].push_back(s);
                    }
                }
                cur[i] = c;
            }
        }
        if (!valid.count(endGene)) return -1;

        queue<string> q;
        q.push(startGene);
        valid.erase(startGene);
        int res = 0;
        while(!q.empty()) {
            int t = q.size();
            while (t--) {
                string cur = q.front();
                q.pop();
                for (auto &neighbor: dict[cur]) {
                    if (neighbor == endGene) return res + 1;
                    if (!valid.count(neighbor)) continue;
                    q.push(neighbor);
                    valid.erase(neighbor);
                }
            }
            res++;
        }
        return -1;
    }
};