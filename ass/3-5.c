#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	char* pc;
	int* pi;
	float* pf;
	double* pd;

	/*char* pc = NULL;
	int* pi = NULL;
	float* pf = NULL;
	double* pd = NULL;*/

	char c;
	int i;
	float f;
	double d;

	printf("초기화하기전의 pc = %lu\n", pc);
	pc = &c;
	printf("초기화하기후의 pc = %lu\n", pc);
	*pc = 100;
	printf("c = %d\n", c);

	printf("초기화하기전의 pi = %lu\n", pi);
	pi = &i;
	printf("초기화하기후의 pi = %lu\n", pi);
	*pi = 100;
	printf("i = %d\n", i);

	printf("초기화하기전의 pf = %lu\n", pf);
	pf = &f;
	printf("초기화하기후의 pf = %lu\n", pf);
	*pf = 100;
	printf("f = %f\n", f);

	printf("초기화하기전의 pd = %lu\n", pd);
	pd = &d;
	printf("초기화하기후의 pd = %lu\n", pd);
	*pd = 100;
	printf("d = %f\n", d);
}