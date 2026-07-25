// Problem: Rod Cutting
// Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int N = price.size();
        vector<int> prev(N + 1, 0);
        for(int n = 0; n <= N; n++) {
            prev[n] = price[0] * n;
        }
        for(int i = 1; i < N; i++) {
            vector<int> cur(N + 1, 0);
            for(int n = 0; n <= N; n++) {
                int not_take = prev[n];
                int take = n > i ? price[i] + cur[n - i - 1] : -1e9;
                cur[n] = max(take, not_take);
            }
            prev = cur;
        }
        return prev[N];
    }
    /*
    int cutRod(vector<int> &price) {
        int N = price.size();
        vector<vector<int>> dp(N, vector<int>(N + 1, 0));
        for(int n = 0; n <= N; n++) {
            dp[0][n] = price[0] * n;
        }
        for(int i = 1; i < N; i++) {
            for(int n = 0; n <= N; n++) {
                int not_take = dp[i - 1][n];
                int take = n > i ? price[i] + dp[i][n - i - 1] : -1e9;
                dp[i][n] = max(take, not_take);
            }
        }
        return dp[N - 1][N];
    }
    */
    /*
    int f(int ind, int N, vector<int>& price,
            vector<vector<int>>& dp) {
        if(ind == 0) {
            return N * price[0];
        }
        if(dp[ind][N] != -1) {
            return dp[ind][N];
        }
        int not_take = f(ind - 1, N, price, dp);
        int take = N > ind ? price[ind] + f(ind, N - ind - 1, price, dp) : -1e9;
        return dp[ind][N] = max(take, not_take);
    }
    int cutRod(vector<int> &price) {
        int N = price.size();
        vector<vector<int>> dp(N, vector<int>(N + 1, -1));
        return f(N - 1, N, price, dp);
    }
    */
};
