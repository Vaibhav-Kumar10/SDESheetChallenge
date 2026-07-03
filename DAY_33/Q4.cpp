// Problem: Morris Inorder Traversal 
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    /*
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    */
    void morrisInorder(TreeNode* root, vector<int>& ans) {
        TreeNode* cur = root;
        // Loop until the current node is not NULL
        while (cur != NULL) {
            // If the current node's left child is NULL
            if (cur->left == NULL) {
                // Add the value of the current node to the inorder vector
                ans.push_back(cur->val);
                // Move to the right child
                cur = cur->right;
            } else {
                // If the left child is not NULL, find the predecessor
                // (rightmost nodein the left subtree)
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                // If the predecessor's right child is NULL, establish a
                // temporary link and move to the left child
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // If the predecessor's right child is already linked,
                    // remove the link, add current node to ans vector, and move
                    // to the right child
                    prev->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        morrisInorder(root, ans);
        // inorder(root, ans);
        return ans;
    }
};
