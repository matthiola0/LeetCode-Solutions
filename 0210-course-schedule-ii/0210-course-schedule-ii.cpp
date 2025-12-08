class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> res;
        for (vector<int> p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                res.push_back(i);
            }

        }

        while (!q.empty()) {
            int f = q.front();
            q.pop();

            for (int i : adj[f]) {
                indeg[i]--;
                if (indeg[i] == 0) {
                    q.push(i);
                    res.push_back(i);
                }
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] != 0) return {};
        }
        return res;
    }
};