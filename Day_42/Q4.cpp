// Problem: Kth Largest in BST
// Link: https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
/* Structure of a Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    int f(Node* root, int &cnt, int k) {
        if (root == NULL) {
            return -1;
        }

        int right = f(root->right, cnt, k);
        if (right != -1) {
            return right;
        }
        
        cnt++;
        if (cnt == k) {
            return root->data;
        }
            
        int left = f(root->left, cnt, k);
        return left;
    }
    
    int kthLargest(Node* root, int k) {
        int cnt = 0;
        return f(root, cnt, k);
    }
};
