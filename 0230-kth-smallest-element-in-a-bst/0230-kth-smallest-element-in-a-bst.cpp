/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    stack<int> stk;
    void traverse(TreeNode* node, int k) {
        if (node == nullptr || stk.size() == k) return;
        traverse(node->left, k);
        if (stk.size() == k) return;
        stk.push(node->val);
        traverse(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return 0;
        traverse(root, k);
        return stk.top();
    }
};