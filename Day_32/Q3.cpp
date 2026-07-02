// Problem: Compare Version Numbers
// Link: https://leetcode.com/problems/compare-version-numbers/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l = 0, r = 0, n = version1.size(), m = version2.size();
        int num1 = 0, num2 = 0;
        while (l < n || r < m) {
            // build the number, until '.'
            while (l < n && version1[l] != '.') {
                num1 = (num1 * 10) + (version1[l] - '0');
                l++;
            }
            while (r < m && version2[r] != '.') {
                num2 = (num2 * 10) + (version2[r] - '0');
                r++;
            }
            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
            l++;
            r++;
            num1 = 0;
            num2 = 0;
        }
        return 0;
    }
};
