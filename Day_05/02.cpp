// Problem: Pow(x, n)
// Link: https://leetcode.com/problems/powx-n/
// Approach: Implement the power function maually
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long exp = n;
        // If negative power => make the power positive and inverse the base
        if (n < 0) {
            x = 1.0 / x;
            exp = -1 * exp;
        }
        double base = x;
        while (exp > 0) {
            // Odd power
            // if (exp % 2 == 1) {
            if (exp & 1) {
                ans = ans * base;
            }
            // Square the base
            base = base * base;
            // exp = exp / 2;
            exp = exp >> 1;
        }
        return ans;
    }
};
