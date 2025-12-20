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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd, 
                    unordered_map<int, int>& mp) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = build(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mp);
        root->right = build(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;     // value, inorder idx
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, n-1, inorder, 0, n-1, mp);
    }
};