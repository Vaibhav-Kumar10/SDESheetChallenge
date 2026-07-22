// Problem: Longest Common Subsequence
// Link: https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> prev(m + 1, 0);
        for (int j = 0; j <= m; j++) {
            prev[j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            vector<int> cur(m + 1, 0);
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    cur[j] = 1 + prev[j - 1];
                } else {
                    int a = prev[j];
                    int b = cur[j - 1];
                    cur[j] = max(a, b);
                }
            }
            prev = cur;
        }
        return prev[m];
    }
    /*
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    int a = dp[i - 1][j];
                    int b = dp[i][j - 1];
                    dp[i][j] = max(a, b);
                }
            }
        }
        return dp[n][m];
    }
    */
    /*
    int f(int ind1, int ind2, string& s1, string& s2, vector<vector<int>>& dp) {
        if (ind1 == 0 || ind2 == 0) {
            return 0;
        }
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        if (s1[ind1 - 1] == s2[ind2 - 1]) {
            return 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
        }
        int a = f(ind1 - 1, ind2, s1, s2, dp);
        int b = f(ind1, ind2 - 1, s1, s2, dp);
        return dp[ind1][ind2] = max(a, b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, text1, text2, dp);
    }
    */
    /*
    int f(int ind1, int ind2, string& s1, string& s2, vector<vector<int>>& dp) {
        if (ind1 < 0 || ind2 < 0) {
            return 0;
        }
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        if (s1[ind1] == s2[ind2]) {
            return 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
        }
        int a = f(ind1 - 1, ind2, s1, s2, dp);
        int b = f(ind1, ind2 - 1, s1, s2, dp);
        return dp[ind1][ind2] = max(a, b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, text1, text2, dp);
    }
    */
};
