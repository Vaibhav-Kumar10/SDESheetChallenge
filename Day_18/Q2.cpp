// Problem: N-Queens
// Link: https://leetcode.com/problems/n-queens/
class Solution {
public:
    vector<bool> upperLeftDiagonal, lowerLeftDiagonal, leftRows;
    void f(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRows[row] == false &&
                upperLeftDiagonal[n - 1 + col - row] == false &&
                lowerLeftDiagonal[col + row] == false) {

                board[row][col] = 'Q';
                leftRows[row] = true;
                upperLeftDiagonal[n - 1 + col - row] = true;
                lowerLeftDiagonal[col + row] = true;

                f(col + 1, board, ans, n);

                leftRows[row] = false;
                upperLeftDiagonal[n - 1 + col - row] = false;
                lowerLeftDiagonal[col + row] = false;
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        upperLeftDiagonal.assign(2 * n - 1, false);
        lowerLeftDiagonal.assign(2 * n - 1, false);
        leftRows.assign(n, false);

        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        f(0, board, ans, n);
        return ans;
    }
    /*
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int rowCopy = row, colCopy = col;
        // Upper left diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        // Previous column cells in current row
        row = rowCopy;
        col = colCopy;
        while (col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            col--;
        }
        // Lower left diagonal
        row = rowCopy;
        col = colCopy;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void f(int col, vector<string>& board, vector<vector<string>>& ans,
               int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                f(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        f(0, board, ans, n);
        return ans;
    }
    */
};
