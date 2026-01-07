class Solution {
private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
    int encode(const vector<vector<int>>& board) {
        int res = 0;
        int p = 1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                res += board[i][j] * p;
                p *= 10;
            }
        }
        return res;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int ans = 54321;
        if (encode(board) == ans) return 0;

        unordered_set<int> visited;
        visited.insert(encode(board));

        queue<vector<vector<int>>> q;
        q.push(board);
        int step = 0;
        while (!q.empty()) {
            step++;
            int t = q.size();

            while (t--) {
                vector<vector<int>> cur = q.front();
                q.pop();

                bool flag = false;
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 3; j++) {
                        if(cur[i][j] == 0) {

                            for (int k = 0; k < 4; k++) {
                                int ni = i + d[k][0], nj = j + d[k][1];
                                if (ni < 0 || ni >= 2 || nj < 0 || nj >= 3) continue;

                                swap(cur[i][j], cur[ni][nj]);
                                
                                int next = encode(cur);
                                // cout << next << ' ';
                                if (next == ans) return step;
                                if (!visited.count(next)) {
                                    visited.insert(next);
                                    q.push(cur);
                                }

                                swap(cur[i][j], cur[ni][nj]);
                            }

                            flag = true;
                            break;
                        }
                    }
                    if (flag) break;
                }
            }
        }

        return -1;
    }
};