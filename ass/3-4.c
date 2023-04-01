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

	//pc = NULL;을 써서 코드가 돌아가게 한다면
	//char 변수 c의 값이 변경된다.
	printf("초기화하기전의 pc = %lu\n", pc);
	pc = &c;
	printf("초기화하기후의 pc = %lu\n", pc);
	*pc = 100;
	printf("c = %d\n", c);
}