// Çà·Ä ÇÕ
#include <stdio.h>

void addMatrices(int A[][3], int B[][3], int C[][3], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void printC(int C[][3], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int B[2][3] = { {4, 5, 6}, {7, 8, 9} };
    int C[2][3];

    addMatrices(A, B, C, 2, 3);
    printC(C, 2, 3);

    return 0;
}
