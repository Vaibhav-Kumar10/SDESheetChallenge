// Problem: Clone Graph
// Link: https://leetcode.com/problems/clone-graph/
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
    Node* cloneUsingDFS(Node* node, unordered_map<Node*, Node*>& nodes) {
        vector<Node*> nbrs;
        Node* clone_node = new Node(node->val);
        nodes[node] = clone_node;
        for (auto nbr : node->neighbors) {
            if (nodes.find(nbr) != nodes.end()) {
                nbrs.push_back(nodes[nbr]);
            } else {
                nbrs.push_back(cloneUsingDFS(nbr, nodes));
            }
        }
        clone_node->neighbors = nbrs;
        return clone_node;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> nodes;
        if (node == NULL) {
            return NULL;
        }
        if (node->neighbors.size() == 0) {
            Node* clone_node = new Node(node->val);
            return clone_node;
        }
        return cloneUsingDFS(node, nodes);
    }
};
