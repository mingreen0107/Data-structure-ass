#include <stdio.h>
#include <memory.h>

void main()
{
	int *pi;
	pi = (int*)malloc(100*sizeof(char)); //100 > 400
	

	printf("pi = %lu\n", pi);
	
	free(pi);
}