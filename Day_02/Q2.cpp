// Problem: Sort Colors
// Link: https://leetcode.com/problems/sort-colors/
// Approach: Divide the array into 3 parts => 
    // Before left => only 0
    // After  right => only 2
    // Between them only 1 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Before left => only 0
        // After  right => only 2
        // Between them only 1
        int left = 0, mid = 0, right = nums.size() - 1;
        while (mid <= right) {
            // num is 0 => take it to left side
            if (nums[mid] == 0) {
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            }
            // num is 2 => take it to right side
            else if (nums[mid] == 2) {
                swap(nums[right], nums[mid]);
                right--;
            }
            // num is 1 => correct postion
            else {
                mid++;
            }
        }
    }
};
