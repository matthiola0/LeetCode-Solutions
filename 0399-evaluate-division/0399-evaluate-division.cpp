class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj;
        for (int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]][equations[i][1]] = values[i];
            adj[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }

        vector<double> res;
        for (auto q : queries) {
            if (adj.find(q[0]) == adj.end() || adj.find(q[1]) == adj.end()) {
                res.push_back(-1.0);
                continue;
            }

            stack<pair<string, double>> stk;
            unordered_set<string> visited;
            bool found = false;
            stk.push({q[0], 1});
            visited.insert(q[0]);

            while(!stk.empty()) {
                auto [cur_str, cur_val] = stk.top();
                stk.pop();
                if (cur_str == q[1]) {
                    res.push_back(cur_val);
                    found = true;
                    break;
                }
                for (auto next : adj[cur_str]) {
                    if (visited.count(next.first) == 0) {
                        visited.insert(next.first);
                        stk.push({next.first, cur_val * next.second});
                    }
                }
            }
            if (!found) res.push_back(-1.0);
        }
        return res;
    }
};