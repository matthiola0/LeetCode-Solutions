class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<int> indeg(numCourses, 0);
        vector<vector<int>> neighbors(numCourses);
        vector<int> res;
        for (auto p : prerequisites) {
            indeg[p[0]]++;
            neighbors[p[1]].push_back(p[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) 
            if (indeg[i] == 0) q.push(i);
            int finishCourses = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                finishCourses++;
                for (int &i : neighbors[cur]) {
                    indeg[i]--;
                    if (indeg[i] == 0) q.push(i);
            }
        }
        if (finishCourses != numCourses) return {};
        return res;
    }
};