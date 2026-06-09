// Problem: Merge Two Sorted Lists
// Link: https://leetcode.com/problems/merge-two-sorted-lists/
// Approach: Use the logic of merge sort. Create a new linked list. Attach the smaller of the two exisiting lists' node to that new linked list, repeatedly.
// If either of the lists are exhausted, attach the other to the end. 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode *t1 = list1, *t2 = list2, *temp = head;
        while (t1 != NULL && t2 != NULL) {
            if (t1->val <= t2->val) {
                temp->next = t1;
                t1 = t1->next;
            } else {
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        if (t1 != NULL) {
            temp->next = t1;
        }
        if (t2 != NULL) {
            temp->next = t2;
        }
        return head->next;
    }
};
