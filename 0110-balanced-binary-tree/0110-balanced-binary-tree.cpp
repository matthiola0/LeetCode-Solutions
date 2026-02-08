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
    int h(TreeNode* node) {
        if (!node) return 0;
        
        int left = h(node->left);
        if (left == -1) return -1;

        int right = h(node->right);
        if (right == -1) return -1;

        if (abs(right - left) > 1) return -1;

        return 1 + max(right, left); 
    }
public:
    bool isBalanced(TreeNode* root) {
        return h(root) != -1;
    }
};