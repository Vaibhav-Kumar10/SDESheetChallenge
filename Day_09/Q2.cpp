// Problem: Middle of the Linked List
// Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Approach: Use two pointers - slow and fast. slow moves one step at a time, while fast moves two steps at a time. 
// Due to the relative speed, when fast reaches end, slow will be at the middle of the Linked List.
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

        /*
        ListNode* ptr = head;
        int lenLL = 0;
        while (ptr != NULL) {
            ptr = ptr->next;
            lenLL++;
        }
        ptr = head;
        for (int i = 0; i < lenLL / 2; i++) {
            ptr = ptr->next;
        }
        return ptr;
        */
    }
};
