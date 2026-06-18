// Problem: Sudoku Solver
// Link: https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { f(board); }
    bool f(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                // Try all possible numbers from 1 to 9
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (isValid(ch, i, j, board) == true) {
                        board[i][j] = ch;
                        // Try with this number => if solvable => do not try
                        // further numbers
                        if (f(board) == true) {
                            return true;
                        } else {
                            board[i][j] = '.';
                        }
                    }
                }
                // No valid solution found
                return false;
            }
        }
        return true;
    }
    bool isValid(char ch, int row, int col, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) {
                return false;
            }
            if (board[row][i] == ch) {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) {
                return false;
            }
        }
        return true;
    }
};
