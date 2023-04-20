#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void main()
{
	int i;

	char* pc;
	int* pi;
	float* pf;
	double* pd;

	pc = (char*)malloc(100 * sizeof(char));
	pi = (int*)malloc(100 * sizeof(int));
	pf = (float*)malloc(100 * sizeof(float));
	pd = (double*)malloc(100 * sizeof(double));

	// 동적 메모리 공간 실습 코드를 넣으시오.
	for (i = 0; i < 100; i++)
		*pc = 10;
	for (i = 0; i < 400; i++)
		*pi = 20;
	for (i = 0; i < 400; i++)
		*pf = 40.0;
	for (i = 0; i < 800; i++)
		*pd = 80.0;

	printf("pc = %d\n", *pc);
	printf("pi = %d\n", *pi);
	printf("pf = %f\n", *pf);
	printf("pd = %f\n", *pd);
	// 실습 코드 완료
}