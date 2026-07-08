// Problem: Construct Binary Tree from Inorder and Postorder Traversal
// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    int root_index;
    TreeNode* build(vector<int> postorder, vector<int> inorder, int left_index,
                    int right_index) {
        if (left_index >= right_index)
            return NULL;
        TreeNode* root = new TreeNode(postorder[root_index]);
        int inorder_index = map_in_id[postorder[root_index]];
        root_index--;
        root->right = build(postorder, inorder, inorder_index + 1, right_index);
        root->left = build(postorder, inorder, left_index, inorder_index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            map_in_id[inorder[i]] = i;
        root_index = inorder.size() - 1;
        return build(postorder, inorder, 0, inorder.size());
    }
};
