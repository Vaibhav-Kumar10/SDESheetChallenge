// Problem: Lowest Common Ancestor of a Binary Tree
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q)
            return root;
        TreeNode* leftChild = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightChild = lowestCommonAncestor(root->right, p, q);
        if (rightChild == NULL)
            return leftChild;
        else if (leftChild == NULL)
            return rightChild;
        return root;
    }
};
