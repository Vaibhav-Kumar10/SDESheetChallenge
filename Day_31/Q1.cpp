// Problem: Search Pattern
// Link: https://www.geeksforgeeks.org/problems/search-pattern0205/1
class Solution {
  public:
    vector<int> zFunction(string &s) {
        int n = s.length(), l = 0, r = 0;
        vector<int> z(n);

        for (int i = 1; i < n; i++) {
            if (i <= r) {
                int k = i - l;

                // Case 2: reuse the previously computed value
                z[i] = min(r - i + 1, z[k]);
            }

            // Try to extend the Z-box beyond r
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }

            // Update the [l, r] window if extended
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;
    }
    vector<int> search(string &pat, string &txt) {
        string s = pat + '$' + txt;
        vector<int> z = zFunction(s);
        vector<int> pos;
        int m = pat.size();
        for (int i = m + 1; i < z.size(); i++) {
            if (z[i] == m){
                // pat match starts here in txt
                pos.push_back(i - m - 1); 
            }
        }
        return pos;
    }
};
