// Problem: Median of 2 Sorted Arrays of Different Sizes
// Link: https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1
class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if (n > m) {
            return medianOf2(b, a);
        }
        int l = 0, r = n;
        while (l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = (n + m + 1) / 2 - mid1;
            int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
            int r1 = (mid1 == n ? INT_MAX : a[mid1]);
            int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
            int r2 = (mid2 == m ? INT_MAX : b[mid2]);
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else {
                    return max(l1, l2);
                }
            }
            if (l1 > r2){
                r = mid1 - 1;
            }
            else{
                l = mid1 + 1;
            }
        }
        return 0;
    }
};
