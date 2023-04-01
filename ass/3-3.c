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

	
	//이 코드는 포인터를 초기화 하지 않았기 때문에 실행되지 않는다.
	//따라서 pc = NULL;을 써서 코드가 돌아가게 하면 된다.
	//A3-3. pc의 값이 내가 원하는 값인 100이 아닌 0이 출력된다. (실행된다고 가정 시)
	printf("pc = %lu\n", pc);
	*pc = 100;
}