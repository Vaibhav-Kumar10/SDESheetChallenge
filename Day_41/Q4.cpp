// Problem: Predecessor and Successor
// Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    Node* getRightMostNode(Node* node) {
        while(node->right != NULL) {
            node = node->right;
        }
        return node;
    }
    Node* getLeftMostNode(Node* node) {
        while(node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* prdscr = NULL, *scsr = NULL, *current = root;
        while(current != NULL) {
            if(current->data < key) {
                prdscr = current;
                current = current->right;
            }
            else if(current->data > key) {
                scsr = current;
                current = current->left;
            }
            else {
                if(current->left !=NULL) {
                    prdscr = getRightMostNode(current->left);
                }
                if(current->right !=NULL) {
                    scsr = getLeftMostNode(current->right);
                }
                break;
            }
        }
        return {prdscr, scsr};
    }
};
