// Problem: Validate Binary Search Tree
// Link: https://leetcode.com/problems/validate-binary-search-tree/
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
        int low = min(p->val, q->val);
        int high = max(p->val, q->val);
        while (root != NULL) {
            if (high < root->val)
                root = root->left;
            else if (low > root->val)
                root = root->right;
            else
                return root;
        }

        return NULL;
    }
};
