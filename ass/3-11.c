#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void main()
{
	int i;
	char* pc;

	pc = (char*)malloc(100);
	for (i = 0; i < 100; i++) {
		*pc = 100;
	}
	printf("c = %d\n", *pc);

	free(pc);
}