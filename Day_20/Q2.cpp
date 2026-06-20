// Problem: Median in a row-wise sorted Matrix
// Link: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
class Solution {
  public:
    int countLessEqual(vector<int>& row, int mid) {
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }
    int median(vector<vector<int>> &mat) {
        int rows = mat.size(), cols = mat[0].size();
        int low = mat[0][0], high = mat[0][cols - 1];

        for (int i = 1; i < rows; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][cols - 1]);
        }

        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            for (int i = 0; i < rows; i++) {
                count += countLessEqual(mat[i], mid);
            }
            // If count is less than half, median is greater
            if (count < (rows * cols + 1) / 2) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};
