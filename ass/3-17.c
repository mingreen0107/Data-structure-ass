#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void main()
{
	int *pi;
	pi = (int*)malloc(100*sizeof(char)); //100 > 400
	
	free(pi);
}