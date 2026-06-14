// Problem: Trapping Rain Water
// Link: https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), total = 0;
        int leftMax = 0, rightMax = 0, left = 0, right = n - 1;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] < leftMax) {
                    total += leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
                left++;
            } else {
                if (height[right] < rightMax) {
                    total += rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
                right--;
            }
        }
        return total;

        // int n = height.size(), total = 0;
        // vector<int> prefixMax(n), suffixMax(n);
        // prefixMax[0] = height[0];
        // suffixMax[n - 1] = height[n - 1];
        // for (int i = 1; i < n; i++) {
        //     prefixMax[i] = max(prefixMax[i - 1], height[i]);
        // }
        // for (int i = n - 2; i >= 0; i--) {
        //     suffixMax[i] = max(suffixMax[i + 1], height[i]);
        // }
        // for (int i = 0; i < n; i++) {
        //     if (height[i] < prefixMax[i] && height[i] < suffixMax[i]) {
        //         total += min(prefixMax[i], suffixMax[i]) - height[i];
        //     }
        // }
        // return total;
    }
};
