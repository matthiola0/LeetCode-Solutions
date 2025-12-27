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
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int t = q.size();
            TreeNode* cur;
            while (t--) {
                cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(cur->val);
        }
        return res;
    }
};