// Problem: Maximum Depth of Binary Tree
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    */
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int maxDepth = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            maxDepth = max(maxDepth, depth);
            if (node->left != NULL) {
                q.push({node->left, 1 + depth});
            }
            if (node->right != NULL) {
                q.push({node->right, 1 + depth});
            }
        }
        return maxDepth;
    }
};
