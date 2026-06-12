// Problem: Linked List Cycle II
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Approach: Use two pointers - fast and slow. Move them with different speeds. 
// When they meet => 
// if it is null => no cycle
// else => cycle. 
// Start any of the slow or fast again from head, and find when they meet. It is the start of the cycle.
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
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        // Use 2 pointers - moving with different speeds.
        // When they meet, that is the point of cycle
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                // Cycle found
                slow = head;
                while (slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        // No cycle found
        return NULL;
    }
};
