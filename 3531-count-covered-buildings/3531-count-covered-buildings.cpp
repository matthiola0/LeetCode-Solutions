class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> v0(n+1, vector<int>(2, 0)), v1(n+1, vector<int>(2, 0));
        for (auto b : buildings) {
            if (v0[b[0]][0] == 0) v0[b[0]][0] = b[1];
            else v0[b[0]][0] = min(v0[b[0]][0], b[1]);
            v0[b[0]][1] = max(v0[b[0]][1], b[1]);

            if (v1[b[1]][0] == 0) v1[b[1]][0] = b[0];
            else v1[b[1]][0] = min(v1[b[1]][0], b[0]);
            v1[b[1]][1] = max(v1[b[1]][1], b[0]);
        }
        
        int res = 0;
        for (auto b : buildings) {
            if (v0[b[0]][0] < b[1] && b[1] < v0[b[0]][1] && 
                v1[b[1]][0] < b[0] && b[0] < v1[b[1]][1]) {
                    res++;
                }
        }
        return res;
    }
};