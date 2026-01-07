/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<long long> allSums;

    long long treeSum(TreeNode* node) {
        if (node == nullptr) return 0;
        
        long long currentSum = treeSum(node->left) + treeSum(node->right) + node->val;
        allSums.push_back(currentSum);
        
        return currentSum;
    }

public:
    int maxProduct(TreeNode* root) {
        long long totalSum = treeSum(root);
        long long maxProd = 0;
        
        for (long long sum : allSums) {
            long long product = sum * (totalSum - sum);
            maxProd = max(maxProd, product);
        }
        
        return maxProd % 1000000007;
    }
};