class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string* word;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            word = nullptr;
        }
    };

    TrieNode* root;

    void insert(string& w) {
        TrieNode* node = root;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->word = &w;
    }

    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    void dfs(vector<vector<char>> &board, int r, int c, TrieNode *node, vector<string> &res) {
        char ch = board[r][c];
        int idx = ch - 'a';
        if (board[r][c] == '#' || !node->children[idx]) return;
        
        TrieNode *cur = node->children[idx];
        if (cur->word) {
            res.push_back(*cur->word);
            cur->word = nullptr;
        }

        board[r][c] = '#';

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                dfs(board, nr, nc, cur, res);
            }
        }
        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (auto &w: words) insert(w);

        vector<string> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (root->children[board[i][j] - 'a']) {
                    dfs(board, i, j, root, res);
                }
            }
        }

        return res;
    }
};