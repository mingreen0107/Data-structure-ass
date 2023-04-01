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

	//pc = NULL;을 써야지 코드가 실행된다.
	//만약 포인터를 최기화 시켜주어 코드를 실행해보면 char 변수 c의 값이 변경된다.
	printf("초기화하기전의 pc = %lu\n", pc);
	pc = &c;
	printf("초기화하기후의 pc = %lu\n", pc);
	*pc = 100;
	printf("c = %d\n", c);
}