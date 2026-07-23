// Problem: Edit Distance
// Link: https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i == 0) {
            return j;
        }
        if (j == 0) {
            return i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i - 1] == s2[j - 1]) {
            return f(i - 1, j - 1, s1, s2, dp);
        }
        int insertOps = 1 + f(i, j - 1, s1, s2, dp);
        int deleteOps = 1 + f(i - 1, j, s1, s2, dp);
        int replaceOps = 1 + f(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = min({insertOps, deleteOps, replaceOps});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, word1, word2, dp);
    }
    /*
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i < 0) {
            return j + 1;
        }
        if (j < 0) {
            return i + 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) {
            return f(i - 1, j - 1, s1, s2, dp);
        }
        int insertOps = 1 + f(i, j - 1, s1, s2, dp);
        int deleteOps = 1 + f(i - 1, j, s1, s2, dp);
        int replaceOps = 1 + f(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = min({insertOps, deleteOps, replaceOps});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, word1, word2, dp);
    }
    */
};
