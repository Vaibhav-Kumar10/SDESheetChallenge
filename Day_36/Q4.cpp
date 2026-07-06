// Problem: Balanced Binary Tree
// Link: https://leetcode.com/problems/balanced-binary-tree/
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        if ((left_height == -1) || (right_height == -1) ||
            (abs(left_height - right_height) > 1)) {
            return -1;
        }
        return max(left_height, right_height) + 1;
    }
    bool isBalanced(TreeNode* root) { return maxDepth(root) != -1; }
    /*
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        if (abs(left_height - right_height) > 1) {
            return false;
        }
        bool left_balanced = isBalanced(root->left);
        bool right_balanced = isBalanced(root->right);
        return left_balanced && right_balanced;
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    */
};
