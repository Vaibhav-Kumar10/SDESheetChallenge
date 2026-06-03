// Problem: Merge Sorted Array
// Link: https://leetcode.com/problems/merge-sorted-array/
// Approach: Use two pointers to place the numbers at correct position
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1, right = n - 1, correctIndex = m + n - 1;
        while (left >= 0 && right >= 0) {
            if (nums1[left] > nums2[right]) {
                nums1[correctIndex] = nums1[left];
                left--;
            } else {
                nums1[correctIndex] = nums2[right];
                right--;
            }
            correctIndex--;
        }
        while (right >= 0) {
            nums1[correctIndex] = nums2[right];
            right--;
            correctIndex--;
        }

        // vector<int> arr(m + n);
        // int left = 0, right = 0, index = 0;
        // while (left < m && right < n) {
        //     if (nums1[left] <= nums2[right]) {
        //         arr[index] = nums1[left];
        //         index++;
        //         left++;
        //     } else {
        //         arr[index] = nums2[right];
        //         index++;
        //         right++;
        //     }
        // }
        // while (left < m) {
        //     arr[index] = nums1[left];
        //     index++;
        //     left++;
        // }
        // while (right < n) {
        //     arr[index] = nums2[right];
        //     index++;
        //     right++;
        // }
        // for (int i = 0; i < (n + m); i++) {
        //     nums1[i] = arr[i];
        // }
    }
};
