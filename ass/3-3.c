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

	
	//�� �ڵ�� �����͸� �ʱ�ȭ ���� �ʾұ� ������ ������� �ʴ´�.
	//���� pc = NULL;�� �Ἥ �ڵ尡 ���ư��� �ϸ� �ȴ�.
	//A3-3. pc�� ���� ���� ���ϴ� ���� 100�� �ƴ� 0�� ��µȴ�. (����ȴٰ� ���� ��)
	printf("pc = %lu\n", pc);
	*pc = 100;
}