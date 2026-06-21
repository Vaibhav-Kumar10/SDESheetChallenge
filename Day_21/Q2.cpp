// Problem: K-th element of two Arrays
// Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int m = a.size(), n = b.size();
        if (m > n) {
            return kthElement(b, a, k); 
        }
        int left = k; 
        int low = max(0, k - n), high = min(k, m);
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < m) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n) ? b[mid2] : INT_MAX;
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } 
            else if (l1 > r2) {
                high = mid1 - 1;
            } 
            else {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};
