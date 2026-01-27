class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e: edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], 2 * e[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();

            if (cur == n - 1) return d;

            if (d > dist[cur]) continue;

            for (auto& e: adj[cur]) {
                int v = e.first;
                int w = e.second;

                if (dist[cur] + w < dist[v]) {
                    dist[v] = dist[cur] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};