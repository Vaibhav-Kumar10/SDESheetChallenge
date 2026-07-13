// Problem: Serialize and Deserialize Binary Tree
// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return to_string(reinterpret_cast<uintptr_t>(root));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        uintptr_t addr = stoull(data);
        return reinterpret_cast<TreeNode*>(addr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
