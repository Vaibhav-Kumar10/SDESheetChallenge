// Problem: Majority Element
// Link: https://leetcode.com/problems/majority-element/
// Approach: Use the Boyer-Moore Majority Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // using the Boyer-Moore Majority Voting Algorithm
        int votes = 0, candidate = -1, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (votes == 0) {
                candidate = nums[i];
                votes++;
            } else if (nums[i] == candidate) {
                votes++;
            } else {
                votes--;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate) {
                cnt++;
            }
        }
        if (cnt > n / 2) {
            return candidate;
        }
        return -1;
    }
};
