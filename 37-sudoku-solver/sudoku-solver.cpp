#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }
private:
    bool solve(std::vector<std::vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
            
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (isValid(board, row, col, ch)) {
                            board[row][col] = ch;

                            if (solve(board)) {
                                return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; ++i) {
            // Check row constraint
            if (board[row][i] == ch) return false;
            
            // Check column constraint
            if (board[i][col] == ch) return false;
            
            // Check 3x3 sub-box constraint
            int boxRow = 3 * (row / 3) + (i / 3);
            int boxCol = 3 * (col / 3) + (i % 3);
            if (board[boxRow][boxCol] == ch) return false;
        }
        return true;
    }
};