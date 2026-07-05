// Problem: Root to Leaf Paths 
// Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    void collectPaths(Node *node, vector<int> &path,
            vector<vector<int>> &paths) {
        if (node == NULL) {
            return;
        }
        path.push_back(node->data);
        if (node->left == NULL && node->right == NULL) { 
            paths.push_back(path);
        }
        else {
            collectPaths(node->left, path, paths);
            collectPaths(node->right, path, paths);
        }
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> paths;
        vector<int> path;
        collectPaths(root, path, paths);
        return paths;
    }
};
