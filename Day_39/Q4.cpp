// Problem: Children Sum in a Binary Tree
// Link: https://www.geeksforgeeks.org/problems/children-sum-parent/1
/* Structure of a Tree Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
}; */
class Solution {
	public:
	bool isSumProperty(Node *root) {
		// Empty Single node
		if (root == NULL || (root->left == NULL && root->right == NULL)) {
			return true;
		}
		int leftSum = root->left != NULL ? root->left->data : 0;
		int rightSum = root->right != NULL ? root->right->data : 0;
		int childSum = leftSum + rightSum;
		
		return (root->data == childSum) && 
		    (isSumProperty(root->left) && isSumProperty(root->right)) ;
	}
};
