#include <stdio.h>

void matrix_diff(int* a, int* b, int* c) { 

	int i;

	for (i = 0; i < 10; i++)
	{
		c[i] = a[i] - b[i];
	}
}
int main() {

	//크기가 10인 1차원 배열 a와 b를 임의의 값으로 초기화
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int b[10] = { 0, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//배열 a와 b의 차를 저장할 배열 c를 0으로 초기화
	int c[10] = { 0 };
	int i;

	//배열을 매개값으로 사용함
	matrix_diff(a, b, c);

	for (i = 0; i < 10; i++)
	{
		//올바르게 연산이 이뤄지고 값의 저장이 이뤄졌는지 확인하기 위한 출력
		printf("c[%d] : %d \n", i, c[i]);
	}
	return 0;
}
