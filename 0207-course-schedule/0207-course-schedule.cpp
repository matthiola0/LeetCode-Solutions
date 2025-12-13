class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<int> indeg(numCourses, 0);
        unordered_map<int, vector<int>> neighbors;
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
                finishCourses++;
                for (int i : neighbors[cur]) {
                    indeg[i]--;
                    if (indeg[i] == 0) q.push(i);
            }
        }
        if (finishCourses == numCourses) return true;
        return false;
    }
};

