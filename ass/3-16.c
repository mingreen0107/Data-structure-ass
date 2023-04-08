#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct test {
	int data;
	struct test* link;
} test_str;
void main()
{
	int i;
	test_str* ptest;
	ptest = (double*)malloc(sizeof(test_str)*3);

	for (i = 0; i < 5; i++)
	{
		printf("ptest = %d\n", ptest[i].data);
	}
	free(ptest);
}