// Problem: Word Break
// Link: https://www.geeksforgeeks.org/problems/word-break1352/1
class Solution {
  public:
    bool f(int ind, vector<string>& dictionary, 
            int n, string s, vector<int>& dp) {
        if(ind == n) {
            return true;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        for(string &word : dictionary) {
            if(s.substr(ind, word.size()) == word) {
                if(f(ind + word.size(), dictionary, n, s, dp))
                    return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, dictionary, n, s, dp);
    }
};
