// Problem: Set Matrix Zeroes
// Link: https://leetcode.com/problems/set-matrix-zeroes/
// Approach: Used first row/col as marker — O(1) space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), firstCol = matrix[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // Mark the first column for changing the entire row to 0
                    matrix[i][0] = 0;
                    // Mark the first row for changing the entire column to 0
                    if (j == 0) {
                        firstCol = 0;
                    } else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        // Change every cell to except first row and first column, on the basis
        // of the markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // If 0 in original first row => change the first row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        // If 0 in original first column => change the first column to 0
        if (firstCol == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
