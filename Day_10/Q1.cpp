// Problem: Remove Nth Node From End of List
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head, *temp;
        // Get to the nth node from start
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // If fast reaches last node => the nth node from last is the first node
        if (fast == NULL) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        // Move the slow and fast simultaneously.
        // When fast reaches last node, slow is at nth node from end
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        temp = slow->next;
        slow->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
};
