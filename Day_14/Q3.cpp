// Problem: Max Consecutive Ones
// Link: https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOneCnt = 0, curOneCnt = 0;
        for (int num : nums) {
            // Increase the consecutive one cnt
            if (num == 1) {
                curOneCnt++;
                maxOneCnt = max(maxOneCnt, curOneCnt);
            }
            // Reset the consecutive one cnt to 0, to start from a new sub array
            else {
                curOneCnt = 0;
            }
        }
        return maxOneCnt;
    }
};
