class Solution {
private:
    pair<int, int> calculate(int n, int label) {
        int row = (n-1) - (label-1)/n;
        int col = (label-1) % n;
        if (row % 2 == n % 2) {
            col = (n-1) - col;
        }
        return {row, col};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int res = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int t = q.size();
            while (t--) {
                int cur = q.front();
                q.pop();
                if (cur == n * n) return res;
                for (int i = 1; i <= 6; i++) {
                    if (cur + i > n * n) continue;
                    auto [x, y] = calculate(n, cur + i);
                    if (x < 0) continue;
                    if (board[x][y] == -1) {
                        q.push(cur + i);
                    } else if (board[x][y] == 0) {
                        continue;
                    } else {
                        q.push(board[x][y]);
                    }
                    board[x][y] = 0;
                }    
            }
            res++;
        }
        return -1;
    }
};