// STRASSEN'S MATRIX MULTIPLICATION 
#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void add(int n, int A[n][n], int B[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int n, int A[n][n], int B[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        // Base case
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int new = n / 2;

        // Create sub-matrices
        int A11[new][new], A12[new][new], A21[new][new], A22[new][new];
        int B11[new][new], B12[new][new], B21[new][new], B22[new][new];
        int P1[new][new], P2[new][new], P3[new][new], P4[new][new];
        int P5[new][new], P6[new][new], P7[new][new];
        int temp1[new][new], temp2[new][new];

        // Divide matrices A and B into 4 sub-matrices
        for (int i = 0; i < new; i++) {
            for (int j = 0; j < new; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + new];
                A21[i][j] = A[i + new][j];
                A22[i][j] = A[i + new][j + new];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + new];
                B21[i][j] = B[i + new][j];
                B22[i][j] = B[i + new][j + new];
            }
        }

        // P1 = (A11 + A22) * (B11 + B22)
        add(new, A11, A22, temp1);
        add(new, B11, B22, temp2);
        strassen(new, temp1, temp2, P1);

        // P2 = (A21 + A22) * B11
        add(new, A21, A22, temp1);
        strassen(new, temp1, B11, P2);

        // P3 = A11 * (B12 - B22)
        subtract(new, B12, B22, temp2);
        strassen(new, A11, temp2, P3);

        // P4 = A22 * (B21 - B11)
        subtract(new, B21, B11, temp2);
        strassen(new, A22, temp2, P4);

        // P5 = (A11 + A12) * B22
        add(new, A11, A12, temp1);
        strassen(new, temp1, B22, P5);

        // P6 = (A21 - A11) * (B11 + B12)
        subtract(new, A21, A11, temp1);
        add(new, B11, B12, temp2);
        strassen(new, temp1, temp2, P6);

        // P7 = (A12 - A22) * (B21 + B22)
        subtract(new, A12, A22, temp1);
        add(new, B21, B22, temp2);
        strassen(new, temp1, temp2, P7);

        // C11 = P1 + P4 - P5 + P7
        int C11[new][new], C12[new][new], C21[new][new], C22[new][new];
        add(new, P1, P4, temp1);
        subtract(new, temp1, P5, temp2);
        add(new, temp2, P7, C11);

        // C12 = P3 + P5
        add(new, P3, P5, C12);

        // C21 = P2 + P4
        add(new, P2, P4, C21);

        // C22 = P1 - P2 + P3 + P6
        add(new, P1, P3, temp1);
        subtract(new, temp1, P2, temp2);
        add(new, temp2, P6, C22);

        // Combine
        for (int i = 0; i < new; i++) {
            for (int j = 0; j < new; j++) {
                C[i][j] = C11[i][j];
                C[i][j + new] = C12[i][j];
                C[i + new][j] = C21[i][j];
                C[i + new][j + new] = C22[i][j];
            }
        }
    }
}

void printMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(n, A, B, C);

    printf("Resultant matrix C (A * B):\n");
    printMatrix(n, C);

    return 0;
}


