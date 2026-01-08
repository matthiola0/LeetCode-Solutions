class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (color[i] != 0) continue;

            color[i] = 1;
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int j = 0; j < graph[cur].size(); j++) {
                    int next = graph[cur][j];
                    if (color[next] == color[cur]) return false;

                    if (color[next] == 0) {
                        color[next] = -color[cur];
                        q.push(next);
                    }
                }
            }
        }
        return true;
    }
};