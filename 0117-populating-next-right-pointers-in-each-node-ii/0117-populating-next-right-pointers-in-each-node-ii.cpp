/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int t = q.size();
            Node* prev = nullptr;
            while (t--) {
                Node* cur = q.front();
                q.pop();
                if (prev != nullptr) {
                    prev->next = cur;
                }
                prev = cur;
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
        }
        return root;
    }
};