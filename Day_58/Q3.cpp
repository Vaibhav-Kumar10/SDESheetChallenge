// Problem: All Subsequences of a String
// Link: https://www.geeksforgeeks.org/problems/power-set4302/1
class Solution {
  public:
    void f(int ind, string& s, int n, string& cur, 
            vector<string>& ans) {
        if(ind >= n) {
            ans.push_back(cur);
            return;
        }
        // Take 
        cur += s[ind];
        f(ind + 1, s, n, cur, ans);
        cur.pop_back();
        // Not Take
        f(ind + 1, s, n, cur, ans);
    }
    vector<string> powerSet(string &s) {
        string cur;
        vector<string> ans;
        f(0, s, s.size(), cur, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
