class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);
        int tekedCourses = 0;
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (auto i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                tekedCourses++;
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto neighbor : adj[cur]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) {
                    q.push(neighbor);
                    tekedCourses++;
                }
            }
        }
        return numCourses == tekedCourses;
    }
};