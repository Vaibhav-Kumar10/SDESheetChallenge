// Problem: Construct Binary Search Tree from Preorder Traversal
// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    TreeNode* buildTree(vector<int>& pre, int& index, int leftLimit,
                        int rightLimit) {
        if (index >= pre.size())
            return NULL;

        if (leftLimit >= pre[index] || pre[index] >= rightLimit)
            return NULL;

        TreeNode* root = new TreeNode(pre[index++]);
        root->left = buildTree(pre, index, leftLimit, root->val);
        root->right = buildTree(pre, index, root->val, rightLimit);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int leftLimit = INT_MIN;
        int rightLimit = INT_MAX;
        int index = 0;
        return buildTree(preorder, index, leftLimit, rightLimit);
    }
};
