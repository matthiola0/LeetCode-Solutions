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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd, unordered_map<int, int>& index) {
        if (inorderStart > inorderEnd || postorderStart > postorderEnd) return nullptr;
        
        int rootVal = postorder[postorderEnd];
        TreeNode *root = new TreeNode(rootVal);
        int idx = index[rootVal];
        root->left = helper(inorder, postorder, inorderStart, idx - 1, postorderStart, postorderStart + idx - inorderStart - 1, index);
        root->right = helper(inorder, postorder, idx + 1, inorderEnd, postorderStart + idx - inorderStart, postorderEnd - 1, index);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, index);
    }
};