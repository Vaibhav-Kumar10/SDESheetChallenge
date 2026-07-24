// Problem: Subset Sum Problem
// Link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
class Solution {
  public:
    bool f(int ind, int target, vector<int>& arr,
            vector<vector<int>>& dp) {
        if(target == 0) {
            return true;
        }
        if(ind == 0) {
            return target == arr[ind];
        }

        if(dp[ind][target] != -1) {
            return dp[ind][target];
        }

        bool not_take = f(ind - 1, target, arr, dp);
        bool take = false;
        if(target >= arr[ind]) {
            take = f(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take || not_take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, arr, dp);
    }
};
