// Problem: Diameter of Binary Tree
// Link: https://leetcode.com/problems/diameter-of-binary-tree/
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int maxDiameter = 0;
        maxDepth(root, maxDiameter);
        return maxDiameter;
    }
    int maxDepth(TreeNode* root, int& maxDiameter) {
        if (root == NULL) {
            return 0;
        }

        int left_height = maxDepth(root->left, maxDiameter);
        int right_height = maxDepth(root->right, maxDiameter);

        maxDiameter = max(left_height + right_height, maxDiameter);

        return max(left_height, right_height) + 1;
    }
    /*
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);

        return max({left_height + right_height,
                    diameterOfBinaryTree(root->left),
                    diameterOfBinaryTree(root->right)});
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    */
};
