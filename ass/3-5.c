#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	char* pc;
	int* pi;
	float* pf;
	double* pd;

	char c;
	int i;
	float f;
	double d;

	pc = NULL;
	printf("초기화하기전의 pc = %lu\n", pc);
	pc = &c;
	printf("초기화하기후의 pc = %lu\n", pc);
	*pc = 100;
	printf("c = %d\n\n", c);

	pi = NULL;
	printf("초기화하기전의 pi = %lu\n", pi);
	pi = &i;
	printf("초기화하기후의 pi = %lu\n", pi);
	*pi = 100;
	printf("i = %d\n\n", i);

	pf = NULL;
	printf("초기화하기전의 pf = %lu\n", pf);
	pf = &f;
	printf("초기화하기후의 pf = %lu\n", pf);
	*pf = 100;
	printf("f = %f\n\n", f);

	pd = NULL;
	printf("초기화하기전의 pd = %lu\n", pd);
	pd = &d;
	printf("초기화하기후의 pd = %lu\n", pd);
	*pd = 100;
	printf("d = %f\n", d);
}