// Problem: Binary Tree Maximum Path Sum
// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int f(TreeNode* root, int& max_path_sum) {
        if (root == NULL) {
            return 0;
        }
        // Skip -ve paths by using 0
        int left_path_sum = max(0, f(root->left, max_path_sum));
        int right_path_sum = max(0, f(root->right, max_path_sum));
        // update max path sum
        max_path_sum =
            max(max_path_sum, root->val + left_path_sum + right_path_sum);
        // return the path sum at cur node
        int cur_path_sum = root->val + max(left_path_sum, right_path_sum);
        return cur_path_sum;
    }
    int maxPathSum(TreeNode* root) {
        int max_path_sum = INT_MIN;
        f(root, max_path_sum);
        return max_path_sum;
    }
};
