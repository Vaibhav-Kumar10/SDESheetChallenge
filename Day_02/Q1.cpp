// Problem: Maximum Subarray
// Link: https://leetcode.com/problems/maximum-subarray/
// Approach: Maintain sum of array elemnts, and update the maximum sum everytime. If at any time, if the sum is negative, make it 0.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), curSum = 0, maxSum = INT_MIN;
        for (int num : nums) {
            curSum += num;
            maxSum = max(maxSum, curSum);
            // If negative sum, update to 0
            if (curSum < 0) {
                curSum = 0;
            }
        }
        return maxSum;
    }
};
