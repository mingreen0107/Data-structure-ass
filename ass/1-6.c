#include <stdio.h>
void printArrayAddress(int[][3]);

void main(void)
{
	int array[2][3] = { {1, 2, 3}, {4, 5, 6} };

	printf("�迭 array�� ��� : \n");
	printArrayAddress(array);
}

void printArrayAddress(int a[][3])
{
	int i, j;

	for (i = 0; i <= 1; i++)
	{
		for (j = 0; j <= 2; j++)
			printf("%p ", &a[i][j]);
		printf("\n");
	}
}