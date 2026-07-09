// Problem: Flatten Binary Tree to Linked List
// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* flat_bt(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* leftTail = flat_bt(root->left);
        TreeNode* rightTail = flat_bt(root->right);

        if (leftTail != NULL) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        if (rightTail != NULL) {
            return rightTail;
        }
        if (leftTail != NULL) {
            return leftTail;
        }
        return root;
    }
    void flatten(TreeNode* root) { flat_bt(root); }
};
