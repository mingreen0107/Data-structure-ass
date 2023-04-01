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

	//A3-3.pc의 값이 내가 원하는 100이 아닌 0이 출력된다.
	//따라서 pc = NULL;을 써서 코드가 돌아가게 하면 된다.
	printf("pc = %lu\n", pc);
	*pc = 100;
}