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

	//pc = NULL;�� �Ἥ �ڵ尡 ���ư��� �Ѵٸ�
	//char ���� c�� ���� ����ȴ�.
	printf("�ʱ�ȭ�ϱ����� pc = %lu\n", pc);
	pc = &c;
	printf("�ʱ�ȭ�ϱ����� pc = %lu\n", pc);
	*pc = 100;
	printf("c = %d\n", c);
}