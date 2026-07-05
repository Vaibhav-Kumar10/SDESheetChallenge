// Problem: Maximum Width of Binary Tree
// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, long long>> q;
        long long max_width = 0;
        q.push({root, 1});
        while (!q.empty()) {
            int level_size = q.size();
            long long min_idx = q.front().second;
            long long left = 0, right = 0;
            while (level_size--) {
                auto [node, idx] = q.front();
                q.pop();

                long long cur_idx = idx - min_idx;

                left = min(left, cur_idx);
                right = max(right, cur_idx);

                if (node->left != NULL) {
                    q.push({node->left, 2 * cur_idx + 1});
                }

                if (node->right != NULL) {
                    q.push({node->right, 2 * cur_idx + 2});
                }
            }
            max_width = max(max_width, right - left + 1);
        }
        return max_width;
    }
};
