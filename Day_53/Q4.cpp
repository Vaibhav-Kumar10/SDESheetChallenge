// Problem: Matrix Chain Multiplication
// Link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
class Solution {
  public:
    int f(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i == j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int minCost = INT_MAX;
        for (int k = i; k < j; k++) {
            int cost1 = f(arr, i, k, dp);
            int cost2 = f(arr, k + 1, j, dp);
            int costMultiply = arr[i - 1] * arr[k] * arr[j];

            int total = cost1 + cost2 + costMultiply;

            minCost = min(minCost, total);
        }

        return dp[i][j] = minCost;
    }
    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(arr, 1, n - 1, dp);
    }
};
