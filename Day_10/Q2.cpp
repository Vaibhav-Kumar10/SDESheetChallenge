// Problem: Add Two Numbers
// Link: https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* head = new ListNode(-1);
        ListNode *t1 = l1, *t2 = l2, *temp = head;
        // Add the digits of the two lists, and create a node as that sum.
        // then add that node to the new list.
        while (t1 != NULL || t2 != NULL) {
            sum = carry;
            if (t1 != NULL) {
                sum += t1->val;
                t1 = t1->next;
            }
            if (t2 != NULL) {
                sum += t2->val;
                t2 = t2->next;
            }
            // Update the carry, and the sum
            carry = sum / 10;
            sum %= 10;
            ListNode* nextnode = new ListNode(sum);
            temp->next = nextnode;
            temp = temp->next;
        }
        // If carry remains => create a new node with that carry
        if (carry != 0) {
            ListNode* nextnode = new ListNode(carry);
            temp->next = nextnode;
            temp = temp->next;
        }
        return head->next;
    }
};
