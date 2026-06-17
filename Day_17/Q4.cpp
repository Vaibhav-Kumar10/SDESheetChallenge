// Problem: Permutation Sequence
// Link: https://leetcode.com/problems/permutation-sequence/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1), availableDigits;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            availableDigits.push_back(i);
        }
        k--;
        string ans = "";
        while (!availableDigits.empty()) {
            int remPositions = availableDigits.size();
            int permsPerChoice  = fact[remPositions - 1];
            int idx = k / permsPerChoice ;
            int digit = availableDigits[idx];
            ans += to_string(digit);
            availableDigits.erase(availableDigits.begin() + idx);
            k = k % permsPerChoice ;
        }
        return ans;
    }
    /*
    void f(int n, string& cur, vector<string>& ans, set<int>& used) {
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (used.find(i) != used.end()) {
                continue;
            }
            used.insert(i);
            cur += to_string(i);
            f(n, cur, ans, used);
            cur.pop_back();
            used.erase(i);
        }
    }
    string getPermutation(int n, int k) {
        vector<string> ans;
        set<int> used;
        string cur = "";
        f(n, cur, ans, used);
        // sort(ans.begin(), ans.end());
        return ans[k - 1];
    }
    */
};
