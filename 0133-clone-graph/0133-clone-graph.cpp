/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
    	if (node == nullptr) return nullptr;
        unordered_map<int, Node*> dict;
        dict[node->val] = new Node(node->val);
        queue<Node* > q;
        q.push(node);
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (auto nei : cur->neighbors) {
                if (!dict.count(nei->val)) {
                    dict[nei->val] = new Node(nei->val);
                    q.push(nei);
                }
                dict[cur->val]->neighbors.push_back(dict[nei->val]);
            }
        }
        return dict[node->val];
    }
};
