// 넘겨주는 값이 이상함
#include <stdio.h>

void transpose(int mat[][2], int transposed[][3]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            transposed[j][i] = mat[i][j];
            printf("%d ", transposed[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int mat[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int transposed[3][2];
    int i, j;

    transpose(mat, transposed);
    
    return 0;
}