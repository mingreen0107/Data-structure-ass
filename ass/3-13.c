#include <stdio.h>
#include <memory.h>
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
		*pc = 100;
	for (i = 0; i < 400; i++)
		*pi = 400;
	for (i = 0; i < 400; i++)
		*pf = 400;
	for (i = 0; i < 800; i++)
		*pd = 800;

	printf("c = %d\n", *pc);
	printf("c = %d\n", *pi);
	printf("c = %d\n", *pf);
	printf("c = %d\n", *pd);
	// 실습 코드 완료
}