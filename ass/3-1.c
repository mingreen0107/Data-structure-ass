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

	//초기화되지 않은 'pc' 지역 변수를 사용하여 이 코드는 실행되지 않는다.
	//따라서 'pc' 변수를 초기화 시켜주면 된다.
	printf("pc = %lu\n", pc);
}