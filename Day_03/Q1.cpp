// Problem: Rotate Image
// Link: https://leetcode.com/problems/rotate-image/
// Approach: First transpose the matrix, then reverse each row
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // Tranpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each row
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};
