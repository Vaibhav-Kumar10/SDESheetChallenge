// Problem: Longest Increasing Subsequence
// Link: https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLIS = 0;
        vector<int> dp(n, 1);
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (nums[prev] < nums[ind]) {
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
            maxLIS = max(maxLIS, dp[ind]);
        }
        return maxLIS;
    }
    /*
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            vector<int> cur(n + 1, 0);
            for (int prev = ind - 1; prev >= -1; prev--) {
                int notTake = next[prev + 1];
                int take = 0;
                if (prev == -1 || nums[ind] > nums[prev]) {
                    take = 1 + next[ind + 1];
                }
                cur[prev + 1] = max(take, notTake);
            }
            next = cur;
        }
        return next[-1 + 1];
    }
    */
    /*
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int notTake = dp[ind + 1][prev + 1];
                int take = 0;
                if (prev == -1 || nums[ind] > nums[prev]) {
                    take = 1 + dp[ind + 1][ind + 1];
                }
                dp[ind][prev + 1] = max(take, notTake);
            }
        }
        return dp[0][-1 + 1];
    }
    */
    /*
    int f(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            return 0;
        }
        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }
        int notTake = f(ind + 1, prev, nums, dp);
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + f(ind + 1, ind, nums, dp);
        }
        return dp[ind][prev + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }
    */
};
