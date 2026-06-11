// Problem: Intersection of Two Linked Lists
// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int len1 = 0, len2 = 0;
        ListNode *temp1 = headA, *temp2 = headB;
        while (temp1 != NULL) {
            temp1 = temp1->next;
            len1++;
        }
        while (temp2 != NULL) {
            temp2 = temp2->next;
            len2++;
        }
        temp1 = headA, temp2 = headB;
        // Move both heads to same starting length
        // This ensures that both lists have same length to compare
        if (len1 < len2) {
            for (int i = 0; i < len2 - len1; i++) {
                temp2 = temp2->next;
            }
        } else {
            for (int i = 0; i < len1 - len2; i++) {
                temp1 = temp1->next;
            }
        }
        // Keep moving until both reach any same node
        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};
