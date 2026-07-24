// Problem: Coin Change II
// Link: https://leetcode.com/problems/coin-change-ii/
class Solution {
public:
    int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (ind == 0) {
            return (target % arr[ind] == 0 ? 1 : 0);
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        int not_take = f(ind - 1, target, arr, dp);
        int take = target >= arr[ind] ? f(ind, target - arr[ind], arr, dp) : 0;
        return dp[ind][target] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};
