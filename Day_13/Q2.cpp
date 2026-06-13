// Problem: Copy List with Random Pointer
// Link: https://leetcode.com/problems/copy-list-with-random-pointer/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    void copyNodesInBetween(Node*& head) {
        Node* cur_node = head;
        while (cur_node != NULL) {
            // Create a new node in between 2 original nodes
            Node* copy_node = new Node(cur_node->val);
            Node* next_node = cur_node->next;
            copy_node->next = next_node;
            cur_node->next = copy_node;
            // Move cur original node to next original node
            cur_node = next_node;
        }
    }
    void copyRandomPointers(Node*& head) {
        Node* cur_node = head;
        while (cur_node != NULL) {
            Node* copy_node = cur_node->next;
            if (cur_node->random == NULL) {
                copy_node->random = NULL;
            } else {
                // Each node has a copy node
                copy_node->random = cur_node->random->next;
            }
            cur_node = cur_node->next->next;
        }
    }
    Node* createDeepCopy(Node*& head) {
        Node* deep_copy_head = new Node(-1);
        Node *temp = deep_copy_head, *cur_node = head;
        while (cur_node != NULL) {
            // Point to the copy node of cur node
            temp->next = cur_node->next;
            temp = temp->next;
            // Detach that copy node from cur node
            cur_node->next = cur_node->next->next;
            cur_node = cur_node->next;
        }
        return deep_copy_head->next;
    }
    Node* copyRandomList(Node* head) {
        // Create nodes for deep copy in between
        copyNodesInBetween(head);
        // Copy the random pointers for those in between nodes
        copyRandomPointers(head);
        // Create a new linked list from these in between nodes
        Node* deep_copy_head = createDeepCopy(head);
        return deep_copy_head;
    }
};
