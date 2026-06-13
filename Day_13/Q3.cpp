// Problem: 3Sum
// Link: https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            // Skip same duplicate number
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                // Reduce window from right
                if (sum > 0) {
                    k--;
                }
                // Reduce window from left
                else if (sum < 0) {
                    j++;
                }
                // Store answer
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // Skipp duplicate elements
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
