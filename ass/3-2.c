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

	//A3-2. 초기화되지 않은 상태에서 포인터가 가리키는 곳에 데이터를 저장하면 실행이 되지 않는다.
	//따라서 'pc' 변수를 초기화 시켜주면 된다.
	printf("pc = %lu\n", pc);
	*pc = 100;
}