#include <stdio.h>

int main() {
    int m1[2][2], m2[2][2], result[2][2];
    int i, j, k;

    // 첫 번째 행렬 입력 받기
    printf("첫 번째 2x2 행렬을 입력하세요:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    // 두 번째 행렬 입력 받기
    printf("두 번째 2x2 행렬을 입력하세요:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    // 행렬 곱 계산
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (k = 0; k < 2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // 결과 출력
    printf("계산 결과:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*struct 3D{
	int x, y, z;
};

int main() {
	struct 3D point1;
	struct 3D point2 = { 0 };
	struct 3D point3{ 1, 2, 3 };
	3D point4 = { 1, 2, 3 };
}*/

/*int main() {

	int array1[4] = {};
	int array2[4] = { 10 };
	int array3[4] = {10, 20, 30, 40 };
	int array4[ ] = { };
	int array5[ ] = { 10, 20, 30, 40 };
	int array6[2][2] = { 10, 20, 30, 40 };
	int array7[ ][2] = { 10, 20, 30, 40, 50, 60, 70, 80 };
	int array8[2][ ] = { 10, 20, 30, 40, 50, 60, 70, 80 };
}*/