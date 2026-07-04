// Problem: Right View of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
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
    void solve(Node *root, vector<int> &ans, int level){
        if(root == NULL) {
            return; 
        }
        if(ans.size() == level) {
            ans.push_back(root->data);
        }
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
    vector<int> rightView(Node *root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};
