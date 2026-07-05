// Problem: Pre, Post, Inorder in one traversal 
// Link: https://www.geeksforgeeks.org/dsa/preorder-postorder-and-inorder-traversal-of-a-binary-tree-using-a-single-stack/
#include <bits/stdc++.h>
using namespace std;
// Structure of the
// node of a binary tree
struct Node {
    int data;
    struct Node *left, *right;

    Node(int data)     {
        this->data = data;
        left = right = NULL;
    }
};

// Function to print all nodes of a
// binary tree in Preorder, Postorder
// and Inorder using only one stack
void allTraversal(Node* root) {
    vector<int> pre, post, in;
    stack<pair<Node*, int> > s;
    s.push(make_pair(root, 1));
    while (!s.empty()) {
        pair<Node*, int> p = s.top();
        if (p.second == 1) {
            s.top().second++;
            // Insert the current node into preorder, pre[]
            pre.push_back(p.first->data);
            // If left child is not NULL
            if (p.first->left) {
                // Insert the left subtree with status code 1
                s.push(make_pair(
                    p.first->left, 1));
            }
        }
        else if (p.second == 2) {
            s.top().second++;
            // Insert the current node in inorder, in[]
            in.push_back(p.first->data);
            // If right child is not NULL
            if (p.first->right) {
                // Insert the right subtree into the stack with status code 1
                s.push(make_pair(
                    p.first->right, 1));
            }
        }
        else {
            // Push the current node in post[]
            post.push_back(p.first->data);
            s.pop();
        }
    }

    // Printing Preorder
    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++) {
        cout << pre[i] << " ";
    }
    cout << "\n";

    // Printing Inorder
    cout << "Inorder Traversal: ";

    for (int i = 0; i < in.size(); i++) {
        cout << in[i] << " ";
    }
    cout << "\n";

    // Printing Postorder
    cout << "Postorder Traversal: ";

    for (int i = 0; i < post.size(); i++) {
        cout << post[i] << " ";
    }
    cout << "\n";
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    allTraversal(root);
    return 0;
}
