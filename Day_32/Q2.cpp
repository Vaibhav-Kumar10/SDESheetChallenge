// Problem: Count and Say
// Link: https://leetcode.com/problems/count-and-say/
class Solution {
public:
    string count(string s) {
        char ch = s[0];
        int cnt = 1;
        string ans = "";
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ch) {
                cnt++;
            } else {
                ans += to_string(cnt) + ch;
                ch = s[i];
                cnt = 1;
            }
        }
        ans += to_string(cnt) + ch;
        return ans;
    }
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        return count(countAndSay(n - 1));
    }
};
