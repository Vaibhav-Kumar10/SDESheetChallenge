// Problem: Flattening a Linked List
// Link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; 
*/
class Solution {
public:
    Node* merge2LL(Node* head1, Node* head2) {
        Node* dummy = new Node(-1);
        Node *ans = dummy, *t1 = head1, *t2 = head2;
        while (t1 != NULL && t2 != NULL) {
            if (t1->data < t2->data) {
                ans->bottom = t1;
                ans = t1;
                t1 = t1->bottom;
            } else {
                ans->bottom = t2;
                ans = t2;
                t2 = t2->bottom;
            }
            ans->next = NULL;
        }
        if (t1 != NULL) {
            ans->bottom = t1;
        }
        if (t2 != NULL) {
            ans->bottom = t2;
        }
        if (dummy->bottom != NULL) {
            dummy->bottom->next = NULL;
        }
        return dummy->bottom;
    }
    Node* flatten(Node* root) {
        if (root == NULL || root->next == NULL) {
            return root;
        }
        Node* mergeHead = flatten(root->next);
        return merge2LL(root, mergeHead);
    }
};
