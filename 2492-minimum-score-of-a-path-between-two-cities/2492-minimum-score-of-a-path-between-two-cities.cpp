class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(const auto& road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        int min_score = INT_MAX;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for (const auto& edge: graph[node]) {
                int n = edge.first;
                int d = edge.second;

                min_score = min(min_score, d);
                
                if (!visited[n]) {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }

        return min_score;
    }
};