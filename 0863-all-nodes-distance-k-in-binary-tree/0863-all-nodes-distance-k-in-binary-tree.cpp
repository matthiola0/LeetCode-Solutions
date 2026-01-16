/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;

    void build(TreeNode* node, TreeNode* prev) {
        if (!node) return;
        if (prev) {
            parent[node] = prev;
        }

        build(node->left, node);
        build(node->right, node);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        build(root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;
        while(!q.empty()) {
            if (dist == k) {
                while (!q.empty()) {
                    res.push_back(q.front()->val);
                    q.pop();
                }
                return res;
            }

            int size = q.size();
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left && !visited.count(cur->left)) {
                    visited.insert(cur->left);
                    q.push(cur->left);
                }

                if (cur->right && !visited.count(cur->right)) {
                    visited.insert(cur->right);
                    q.push(cur->right);
                }

                if (parent.count(cur) && !visited.count(parent[cur])) {
                    visited.insert(parent[cur]);
                    q.push(parent[cur]);
                }
            }

            dist++;
        }

        return res;
    }
};