// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        for (int i = 0; i < n; i++) {
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
            nums[k] = nums[i];
            k++;
        }

        return k;
    }
};
