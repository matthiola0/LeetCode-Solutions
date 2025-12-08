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
        unordered_map<int, Node*> visited;
        queue<Node*> q;
        visited[node->val] = new Node(node->val);
        for (Node* i : node->neighbors) {
            visited[i->val] = new Node(i->val);
            visited[node->val]->neighbors.push_back(visited[i->val]);
            q.push(i);
        }
        while (!q.empty()) {
            Node* f = q.front();
            q.pop();

            for (Node* i : f->neighbors) {
                if (visited.count(i->val) == 0) {
                    visited[i->val] = new Node(i->val);
                    q.push(i);
                }
                visited[f->val]->neighbors.push_back(visited[i->val]);
            }
        }
        return visited[1];
    }
};