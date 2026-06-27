// Problem: Sliding Window Maximum
// Link: https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            // if window is to be updated
            // Remove elements from the front if they are out of this window's range
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // Now get the previous greater element
            // Remove all elements from the back that are smaller than current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            // Add the current index to the deque
            dq.push_back(i);

            // Once the first window is completed, add front element to result
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;

        // int n = nums.size();
        // vector<int> ans;
        // for (int i = 0; i < n - k + 1; i++) {
        //     int maxEl = nums[i];
        //     for (int j = i; j < i + k; j++) {
        //         maxEl = max(maxEl, nums[j]);
        //     }
        //     ans.push_back(maxEl);
        // }
        // return ans;
    }
};
