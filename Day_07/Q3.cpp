// Problem: Longest Consecutive Sequence
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Approach: Convert the array to set. Thtn, find the smallest number for the sequence to start. Find the length of the sequence, in which next no. is present.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int longest = 0;
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }
        for (auto num : st) {
            // If previous no. is not present in the set.
            if (st.find(num - 1) == st.end()) {
                int x = num, cnt = 1;
                // Find the longest sequence in which next number is present
                while (st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;

        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < n; i++) {
        //     if(prevSmallest == nums[i] - 1){
        //         cnt++;
        //         prevSmallest = nums[i];
        //     }
        //     else if(prevSmallest != nums[i]){
        //         prevSmallest = nums[i];
        //         cnt = 1;
        //     }
        //     longest = max(longest, cnt);
        // }
        // return longest;

        // for (int i = 0; i < nums.size(); i++) {
        //     int cnt = 1, x = nums[i];
        //     while (search(x + 1, nums) == true) {
        //         x++;
        //         cnt++;
        //     }
        //     longest = max(longest, cnt);
        // }
        // return longest;
    }
    // bool search(int el, vector<int> arr) {
    //     for (int i : arr) {
    //         if (i == el) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};
