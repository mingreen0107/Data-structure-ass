#include <stdio.h>
#include <memory.h>

typedef struct test {
	int data;
	struct test* link;
} test_str;
void main()
{
	int i;
	test_str* ptest;
	ptest = (double*)malloc(sizeof(test_str));
	
	printf("ptest = %lu\n", ptest);

	free(ptest);
}