class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        int cnt = 0;
        for (auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            cnt++;

            for (int next : adj[cur]) {
                indeg[next]--;
                if (indeg[next] == 0) {
                    q.push(next);
                }
            }
        }
        if (cnt == numCourses) return true;
        return false;
    }
};