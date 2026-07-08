// Problem: Construct Binary Tree from Preorder and Inorder Traversal
// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    map<int, int> map_in_id;
    int root_index = 0;
    TreeNode* build(vector<int> preorder, vector<int> inorder, int left_index,
                    int right_index) {
        if (left_index >= right_index)
            return NULL;
        TreeNode* root = new TreeNode(preorder[root_index]);
        int inorder_index = map_in_id[preorder[root_index]];
        root_index++;
        root->left = build(preorder, inorder, left_index, inorder_index);
        root->right = build(preorder, inorder, inorder_index + 1, right_index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            map_in_id[inorder[i]] = i;
        return build(preorder, inorder, 0, inorder.size());
    }
};
