// Problem: Rotate List
// Link: https://leetcode.com/problems/rotate-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        // Find the length of the Linked List
        int len = 1;
        ListNode *lastNode = head, *temp = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
            len++;
        }
        k = k % len;
        if (k == 0) {
            return head;
        }
        // Rotate the linked list by changing pointer of k - 1 th node from last
        k = len - k - 1;
        lastNode->next = head;
        // Go to the last k - 1th node
        while (k--) {
            temp = temp->next;
        }
        // Change pointers => head becomes the last kth node
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
