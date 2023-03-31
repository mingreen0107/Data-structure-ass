#include <stdio.h>
#include <stdlib.h>

int main() {

	int random[10] = { 0 };
	int min = 10, max = 0;
	int i;

	for (i = 0; i < 10; i++)
	{
		random[i] = rand() % 10; 

		printf("%d\n", random[i]);
	}
	for (i = 0; i < 10; i++)
	{
		if (min > random[i])
			min = random[i];

		if (max < random[i])
			max = random[i];
	}
	printf("최대값 : %d\n최소값 : %d", max, min);

	return 0;
}
