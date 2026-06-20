// Problem: Find nth root of m
// Link: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
class Solution {
  public:
    int f(int mid, int n, int m) {
        long long mult = 1;
        for(int i = 1; i <= n; i++) { 
            mult = mult * mid;
            // If more than m => not a valid solution
            if(mult > m) {
                // mid^n > m
                return 1;
            }
        }
        if(mult == m) {
            // mid^n == m
            return 0;
        }
        // mid^n < m
        return -1;
    }
    int nthRoot(int n, int m) {
        if (m == 0) {
            return 0;
        }
        int low = 1, high = m;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int x = f(mid, n, m);
            if(x == 0) {
                return mid;
            }
            // Change the search space to lower side
            else if(x == 1) {
                high = mid - 1;
            }
            // Change the search space to higher side
            else {
                low = mid + 1;
            }
        }
        // No integer root found
        return -1;
    }
};
