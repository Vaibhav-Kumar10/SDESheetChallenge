// Problem: Floor in BST
// Link: https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1
/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */
class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int ans = -1;
        while(root != NULL) {
            if(root->data <= k) {
                ans = root->data;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return ans;
    }
};
