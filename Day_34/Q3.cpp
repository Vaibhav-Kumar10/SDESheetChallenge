// Problem: Top View of Binary Tree 
// Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) {
            return {};
        }
        // - ve -> left
        // + ve -> right
        map<int, int> nodesPositioned;

        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            
            if(nodesPositioned.find(pos) == nodesPositioned.end()) {
                nodesPositioned[pos] = node->data;
            }
            if(node->left) {
                q.push({node->left, pos - 1});
            }
            if(node->right) {
                q.push({node->right, pos + 1});
            }
        }
        for(auto posNode : nodesPositioned) {
            ans.push_back(posNode.second);
        }
        return ans;
    }
};
