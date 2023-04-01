#include <stdio.h>
#include <memory.h>

void main()
{
	char* pc;

	//힙 영역에 1바이트 공간을 확보하되, char*형으로 형변환해서 pc를 가리키도록 해라
	//char형 배열 1개 만큼의 힙 메모리를 할당하여
	//반환형을 char*로 형변환하여 저장
	pc = (char*)malloc(1);
	*pc = 100;
	printf("c = %d\n", *pc);
	free(pc);
}