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
    int res;
    int maxPath(TreeNode* node) {
        if (node == nullptr) return 0;
        int left_sum = maxPath(node->left);
        int right_sum = maxPath(node->right);
        res = max(res, left_sum + right_sum + node->val);
        return max(max(left_sum, right_sum) + node->val, 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        res = max(res, maxPath(root));
        return res;
    }
};