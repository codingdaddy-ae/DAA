#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Function to print the solution
void printSolution(int board[MAX][MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    // Check this column on the upper side
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Function to solve the N Queens problem using backtracking and print all solutions
void solveNQueensAllSolutions(int board[MAX][MAX], int row, int N) {
    // If all queens are placed, print the solution
    if (row >= N) {
        printSolution(board, N);
        return;
    }

    // Consider this row and try all columns one by one
    for (int col = 0; col < N; col++) {
        // Check if it's safe to place the queen in board[row][col]
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the rest of the queens
            solveNQueensAllSolutions(board, row + 1, N);

            // If placing queen in board[row][col] doesn't lead to a solution, backtrack
            board[row][col] = 0; // Remove the queen
        }
    }
}

int main() {
    int N;

    // Take input for N
    printf("Enter the number of queens (N): ");
    scanf("%d", &N);

    // Initialize the chessboard
    int board[MAX][MAX] = {0};

    // Solve the N Queens problem and print all solutions
    printf("All solutions for %d queens:\n", N);
    solveNQueensAllSolutions(board, 0, N);

    return 0;
}
