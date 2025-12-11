class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> dict;
        vector<double> res;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            dict[equations[i][0]][equations[i][1]] = values[i];
            dict[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }

        for (auto query : queries) {
            unordered_set<string> visited;
            queue<pair<string, double>> q;
            bool found = false;
            if (dict.count(query[0])) {
                q.push({query[0], 1.0});
                visited.insert(query[0]);
            }
            while(!q.empty()) {
                auto [cur, val] = q.front();
                q.pop();
                visited.insert(cur);
                if (cur == query[1]) {
                    found = true;
                    res.push_back(val);
                    break;
                }

                for (auto neighbor : dict[cur]) {
                    if (!visited.count(neighbor.first)) {
                        q.push({neighbor.first, val * neighbor.second});
                    }
                }
            }
            if (!found) res.push_back(-1);
        }
        return res;
    }
};