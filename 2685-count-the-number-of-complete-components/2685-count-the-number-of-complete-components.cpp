class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int complete_components_count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int v_count = 0;
                int e_count = 0;
                
                auto dfs = [&](auto& self, int node) -> void {
                    visited[node] = true;
                    v_count++;
                    e_count += graph[node].size();
                    
                    for (int neighbor : graph[node]) {
                        if (!visited[neighbor]) {
                            self(self, neighbor);
                        }
                    }
                };
                
                dfs(dfs, i);
                
                if (e_count == v_count * (v_count - 1)) {
                    complete_components_count++;
                }
            }
        }
        
        return complete_components_count;
    }
};