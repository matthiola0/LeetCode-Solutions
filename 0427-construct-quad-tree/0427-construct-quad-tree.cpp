/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* f(vector<vector<int>>& grid, int x0, int y0, int x1, int y1) {
        bool flag = true;
        int m = x1 - x0 + 1, n = y1 - y0 + 1;
        int last = grid[x0][y0];
        for (int i = x0; i <= x1; i++) {
            for (int j = y0; j <= y1; j++) {
                if (grid[i][j] != last) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) {
            return new Node(last, true);
        } 
        Node *res = new Node(last, false);
        res->topLeft = f(grid, x0, y0, x0 + m/2 - 1, y0 + n/2 - 1);
        res->topRight = f(grid, x0, y0 + n/2, x0 + m/2 - 1, y1);
        res->bottomLeft = f(grid, x0 + m/2, y0, x1, y0 + n/2 - 1);
        res->bottomRight = f(grid, x0 + m/2, y0 + n/2, x1, y1);
        return res;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return f(grid, 0, 0, grid.size() - 1, grid[0].size() - 1);
    }
};