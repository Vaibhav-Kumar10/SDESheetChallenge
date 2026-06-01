// Problem: Next Permutation
// Link: https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dipIndex = -1, n = nums.size();
        // Find first dip
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                dipIndex = i;
                break;
            }
        }
        // If no dip found => Already the max number
        if (dipIndex == -1) {
            // Next Permutation is its reverse
            reverse(nums.begin(), nums.end());
            return;
        }
        // Else, find the first digit greater the the dipIndex digit
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[dipIndex]) {
                swap(nums[i], nums[dipIndex]);
                break;
            }
        }
        // Reverse the digits after dipIndex => sort in ascending order
        reverse(nums.begin() + dipIndex + 1, nums.end());
    }
};
