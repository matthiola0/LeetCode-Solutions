class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000") || visited.count(target)) return -1;
        
        int step = 0;

        queue<string> q;
        q.push("0000");
        while (!q.empty()) {
            int t = q.size();

            while (t--) {
                string cur = q.front();
                q.pop();
                if (cur == target) return step;

                for (int i = 0; i < 4; i++) {
                    char origin = cur[i];

                    if (origin == '9') cur[i] = '0';
                    else cur[i] = origin + 1;
                    if (!visited.count(cur)) {
                        visited.insert(cur);
                        q.push(cur);
                    }

                    if (origin == '0') cur[i] = '9';
                    else cur[i] = origin - 1;
                    if (!visited.count(cur)) {
                        visited.insert(cur);
                        q.push(cur);
                    }
                    
                    cur[i] = origin;
                }
            }
            step++;
        }

        return -1;
    }
};