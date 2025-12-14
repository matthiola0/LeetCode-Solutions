class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        queue<pair<int, int>> q;    // node, cost
        q.push({src, 0});
        
        vector<int> dist(n, INT_MAX);   // min dist
        dist[src] = 0;
        int stops = 0;
        while (!q.empty() && stops <= k) {
            int t = q.size();
            while (t--) {
                auto [cur, cost] = q.front();
                q.pop();
                for (auto& neighbor : adj[cur]) {
                    int nextNode = neighbor.first;
                    int price = neighbor.second;
                    
                    if (cost + price < dist[nextNode]) {
                        dist[nextNode] = cost + price;
                        q.push({nextNode, dist[nextNode]});
                    }
                }
            }
            stops++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};