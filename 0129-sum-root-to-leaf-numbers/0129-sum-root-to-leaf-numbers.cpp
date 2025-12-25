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
    int traverse(TreeNode* node, int cur) {
        int res = 0;
        cur = cur * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) return cur;
        if (node->left != nullptr) res += traverse(node->left, cur);
        if (node->right != nullptr) res += traverse(node->right, cur);
        return res;
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        return traverse(root, 0);
    }
};