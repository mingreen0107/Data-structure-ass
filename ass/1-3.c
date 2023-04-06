#include <stdio.h>
//rand()함수를 사용하기 위한 헤더파일
#include <stdlib.h>

int main() {

	int random[10] = { 0 };
	int min = 10, max = 0;
	int i;

	for (i = 0; i < 10; i++)
	{
		//rand() 함수에 들어있는 값들이 크기 때문에
		//rnad() 함수에 의해 난수를 생성하고 그 숫자를 10으로 나눈 나머지를 변수에 대입
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
	//rand()함수는 정말 random으로 정해지는 값이 아니라
	//컴퓨터의 식으로 rand()함수를 돌리기 때문에 항상 같은 값들이 나옴
	printf("최대값 : %d\n최소값 : %d", max, min);

	//만약 값들을 다르게 하고 싶다면
	//srand(time(NULL));을 사용하면 된다.
	//이 함수는 1초 단위로 매번 다른 시드값을 생성해 rand()함수를 호출하는 함수다.

	return 0;
}
