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

	//A3-2. �ʱ�ȭ���� ���� ���¿��� �����Ͱ� ����Ű�� ���� �����͸� �����ϸ� ������ ���� �ʴ´�.
	//���� 'pc' ������ �ʱ�ȭ �����ָ� �ȴ�.
	printf("pc = %lu\n", pc);
	*pc = 100;
}