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

	//���� �����͸� �ֱ�ȭ �����־� �ڵ带 �����غ��� char ���� c�� ���� ����ȴ�.
	pc = NULL;
	printf("�ʱ�ȭ�ϱ����� pc = %lu\n", pc);
	pc = &c;
	printf("�ʱ�ȭ�ϱ����� pc = %lu\n", pc);
	*pc = 100;
	printf("c = %d\n", c);
}