// Problem: Palindrome Linked List
// Link: https://leetcode.com/problems/palindrome-linked-list/
// Approach: Find the middle of the Linked list. Then reverse the second half linked list. Then check if both are having same elements
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        // 1 - Find the middle element of the Linked List
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        // 2 - Divide the Linked List from the middle
        // 3 - Then reverse ths second half of the Linked List
        ListNode *prev = NULL, *cur = mid;
        while (cur != NULL) {
            ListNode* right = cur->next;
            cur->next = prev;
            prev = cur;
            cur = right;
        }
        ListNode* revHead = prev;
        // 4 - Now check if this second reversed half is equal to the first half
        ListNode *temp1 = head, *temp2 = revHead;
        while (temp2 != NULL) {
            if (temp1->val != temp2->val) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};
