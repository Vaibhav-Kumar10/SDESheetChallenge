// Problem: Search a 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix/
// Approach: Use binary search on 2-D matrix, starting from top left corner
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        // Start binary search from top right corner
        int l = 0, r = m - 1;
        while (l < n && r >= 0) {
            if (matrix[l][r] == target) {
                return true;
            }
            // if smaller tha target => move to next row
            else if (matrix[l][r] < target) {
                l++;
            }
            // if larger than target => move towards left side => lefter column
            else {
                r--;
            }
        }
        return false;
    }
};
