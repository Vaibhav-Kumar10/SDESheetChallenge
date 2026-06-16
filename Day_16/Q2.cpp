// Problem: Coin Change
// Link: https://leetcode.com/problems/coin-change/description/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) {
                prev[t] = t / coins[0];
            } else {
                prev[t] = 1e9;
            }
        }
        for (int i = 1; i < n; i++) {
            vector<int> cur(amount + 1, 0);
            for (int t = 0; t <= amount; t++) {
                int not_take = prev[t];
                int take = t >= coins[i] ? 1 + cur[t - coins[i]] : 1e9;
                cur[t] = min(take, not_take);
            }
            prev = cur;
        }
        return prev[amount] == 1e9 ? -1 : prev[amount];
    }
    /*
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) {
                dp[0][t] = t / coins[0];
            } else {
                dp[0][t] = 1e9;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int not_take = dp[i - 1][t];
                int take = t >= coins[i] ? 1 + dp[i][t - coins[i]] : 1e9;
                dp[i][t] = min(take, not_take);
            }
        }

        return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
    }
    */
    /*
    int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target % arr[ind] == 0) {
                return target / arr[ind];
            }
            return 1e9;
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        int not_take = f(ind - 1, target, arr, dp);

        int take =
            target >= arr[ind] ? 1 + f(ind, target - arr[ind], arr, dp) : 1e9;

        return dp[ind][target] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
    */
};
