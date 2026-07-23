// Problem: 0 - 1 Knapsack Problem
// Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> prev(W + 1, 0);
        for(int w = wt[0]; w <= W; w++) {
            prev[w] = val[0];
        }
        for(int i = 1; i < n; i++) {
            // Start from RHS
            for(int w = W; w >= 0; w--) {
                int not_take = prev[w];
                int take = (w >= wt[i] ? val[i] + prev[w - wt[i]]
                                       : INT_MIN);
                // Update prev itself from RHS
                prev[w] = max(take, not_take);
            }
        }
        return prev[W];
    }
    /*
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> prev(W + 1, 0);
        for(int w = wt[0]; w <= W; w++) {
            prev[w] = val[0];
        }
        for(int i = 1; i < n; i++) {
            vector<int> cur(W + 1, 0);
            for(int w = 0; w <= W; w++) {
                int not_take = prev[w];
                int take = (w >= wt[i] ? val[i] + prev[w - wt[i]]
                                            : INT_MIN);
                cur[w] = max(take, not_take);
            }
            prev = cur;
        }
        return prev[W];
    }
    */
    /*
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for(int w = wt[0]; w <= W; w++) {
            dp[0][w] = val[0];
        }
        for(int i = 1; i < n; i++) {
            for(int w = 0; w <= W; w++) {
                int not_take = dp[i - 1][w];
                int take = (w >= wt[i] ? val[i] + dp[i - 1][w - wt[i]]
                                            : INT_MIN);
                dp[i][w] = max(take, not_take);
            }
        }
        return dp[n - 1][W];
    }
    */
    /*
    int f(int ind, int W, vector<int> &val, vector<int> &wt,
            vector<vector<int>>& dp) {
        if(ind == 0) {
            return (W >= wt[0] ? val[0] : 0);
        }
        if(dp[ind][W] != -1) {
            return dp[ind][W];
        }
        int not_take = f(ind - 1, W, val, wt, dp);
        int take = (W >= wt[ind] ? val[ind] + f(ind - 1, W - wt[ind], val, wt, dp) 
                                    : INT_MIN);
        return dp[ind][W] = max(take, not_take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, W, val, wt, dp);
    }
    */
};
