// Problem: Find the Duplicate Number
// Link: https://leetcode.com/problems/find-the-duplicate-number/
// Approach: Use slow an fast pointers, to detect a cycle, where the number is repeated
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        // Get the first position where they meet
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // If they meet again => the number has repeated
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
