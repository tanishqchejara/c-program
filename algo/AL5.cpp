//8 queen problem using backtracking
#include <iostream>
#include <vector>
using namespace std;

// Function to check if a queen can be placed on the board
bool isSafe(vector<vector<bool>> &board, int row, int col, int n) {
    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on the left side
    for (int i = 1; i <= row && i <= col; i++) {
        if (board[row - i][col - i])
            return false;
    }

    // Check lower diagonal on the left side
    for (int i = 1; i <= n - row - 1 && i <= col; i++) {
        if (board[row + i][col - i])
            return false;
    }

    return true;
}

// Function to solve the N-Queen problem using backtracking
bool solveNQueens(vector<vector<bool>> &board, int col, int n) {
    // If all queens are placed, return true
    if (col == n)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = true;

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1, n))
                return true;

            // If placing the queen in board[row][col] doesn't lead to a solution, remove the queen
            board[row][col] = false;
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

int main() {
    int n = 8;
    vector<vector<bool>> board(n, vector<bool>(n, false));

    if (solveNQueens(board, 1, n)) {
        cout << "Solution found:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j])
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}