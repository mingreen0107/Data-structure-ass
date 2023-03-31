#include <stdio.h>

void matrix_diff(int* a, int* b, int* c) { 

	int i;

	for (i = 0; i < 10; i++)
	{
		c[i] = a[i] - b[i];
	}
}
int main() {

	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int b[10] = { 0, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int c[10] = { 0 };
	int i;

	matrix_diff(a, b, c);

	for (i = 0; i < 10; i++)
	{
		printf("c[%d] : %d \n", i, c[i]);
	}
	return 0;
}
