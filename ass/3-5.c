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
	printf("�ʱ�ȭ�ϱ����� pc = %lu\n", pc);
	pc = &c;
	printf("�ʱ�ȭ�ϱ����� pc = %lu\n", pc);
	*pc = 100;
	printf("c = %d\n\n", c);

	pi = NULL;
	printf("�ʱ�ȭ�ϱ����� pi = %lu\n", pi);
	pi = &i;
	printf("�ʱ�ȭ�ϱ����� pi = %lu\n", pi);
	*pi = 100;
	printf("i = %d\n\n", i);

	pf = NULL;
	printf("�ʱ�ȭ�ϱ����� pf = %lu\n", pf);
	pf = &f;
	printf("�ʱ�ȭ�ϱ����� pf = %lu\n", pf);
	*pf = 100;
	printf("f = %f\n\n", f);

	pd = NULL;
	printf("�ʱ�ȭ�ϱ����� pd = %lu\n", pd);
	pd = &d;
	printf("�ʱ�ȭ�ϱ����� pd = %lu\n", pd);
	*pd = 100;
	printf("d = %f\n", d);
}