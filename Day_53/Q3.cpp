// Problem: Max Sum Increasing Subsequence
// Link: https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
class Solution {
  public:
    int f(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if(i == arr.size() + 1) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(j == 0 || arr[i-1] > arr[j-1]) {
            return dp[i][j] = max(arr[i-1] + f(arr, i+1, i, dp),
                                  f(arr, i+1, j, dp));
        }
        return dp[i][j] = f(arr, i+1, j, dp);
    }

    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(arr, 1, 0, dp);
    }
};
