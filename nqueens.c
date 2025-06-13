#include <stdio.h>
#include <stdbool.h>

#define MAX 20

void printSolution(int board[MAX][MAX], int N, int iteration) {
    printf("Solution %d:\n", iteration);
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

void printSolutionVector(int board[MAX][MAX], int N, int iteration) {
    printf("Solution %d Vector: [", iteration);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                printf("%d", j + 1);
                if (i < N - 1)
                    printf(", ");
            }
        }
    }
    printf("]\n\n");
}

bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

void solveNQueensAllSolutions(int board[MAX][MAX], int row, int N, int *iteration) {
    if (row >= N) {
        (*iteration)++;
        printSolution(board, N, *iteration);
        printSolutionVector(board, N, *iteration);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solveNQueensAllSolutions(board, row + 1, N, iteration);
            board[row][col] = 0;
        }
    }
}

int main() {
    int N;

    printf("Enter the number of queens (N): ");
    scanf("%d", &N);

    int board[MAX][MAX] = {0};
    int iteration = 0;

    printf("All solutions for %d queens:\n", N);
    solveNQueensAllSolutions(board, 0, N, &iteration);

    return 0;
}
