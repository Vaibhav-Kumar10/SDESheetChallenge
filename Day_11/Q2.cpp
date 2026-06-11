// Problem: Linked List Cycle
// Link: https://leetcode.com/problems/linked-list-cycle/
// Approach: Use two pointers - fast and slow. Move them with different speeds. 
// When they meet => 
// if it is null => no cycle
// else => cycle
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
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        // Use 2 pointers - moving with different speeds.
        // When they meet, that is the point of cycle
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                return true;
            }
        }
        // No cycle found
        return false;
    }
};
