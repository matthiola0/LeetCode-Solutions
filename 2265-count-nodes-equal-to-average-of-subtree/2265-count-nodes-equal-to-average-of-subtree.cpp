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
    int res = 0;
    pair<int, int> traverse(TreeNode* node) {
        if (node == nullptr) return {0, 0};

        auto [s1, n1] = traverse(node->left);
        auto [s2, n2] = traverse(node->right);

        int s = s1 + s2 + node->val;
        int n = n1 + n2 + 1;

        if (s/n == node->val) res++;
        return {s, n};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return res;
    }
};