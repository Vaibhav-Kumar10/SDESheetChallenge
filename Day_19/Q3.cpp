// Problem: Word Break - 2
// Link: https://www.geeksforgeeks.org/problems/word-break-part-23249/1
class Solution {
  public:
    void f(int ind, string& s, unordered_set<string>& dictSet, 
            string& cur, vector<string>& ans) {
        if(ind == s.size()) {
            ans.push_back(cur);
            return;
        }
        for(int i = ind + 1; i <= s.size(); i++) {
            string word = s.substr(ind, i - ind);
            if(dictSet.find(word) == dictSet.end()) {
                continue;
            }
            string prev = cur;
            if(!cur.empty()) {
                cur += " ";
            }
            cur += word;
            f(i, s, dictSet, cur, ans);
            cur = prev;
        }
    }
    vector<string> wordBreak(vector<string>& dict, string& s) {
        unordered_set<string> dictSet(dict.begin(), dict.end());
        vector<string> ans;
        string cur;
        f(0, s, dictSet, cur, ans);
        return ans;
    }
};
