// Problem: Reverse Nodes in k-Group
// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Approach: Recursively reverse k nodes. If less than k nodes =? return as it is
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL && cnt < k) {
            temp = temp->next;
            cnt++;
        }
        // If less than k nodes present => leave as it is
        if (cnt < k) {
            return head;
        }

        ListNode *cur_node = head, *prev_node = NULL, *next_node;
        // Reverse the k nodes
        while (cnt--) {
            next_node = cur_node->next;
            cur_node->next = prev_node;
            prev_node = cur_node;
            cur_node = next_node;
        }
        // If still nodes remain, reverse them in group of k pairs
        if (cur_node != NULL) {
            head->next = reverseKGroup(cur_node, k);
        }
        return prev_node;
    }
};
