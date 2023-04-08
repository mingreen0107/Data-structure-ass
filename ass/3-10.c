#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void main()
{
	char* pc;

	//힙 영역에 1바이트 공간을 확보하되, char*형으로 형변환해서 pc를 가리키도록 해라
	//char형 배열 1개 만큼의 힙 메모리를 할당하여 반환형을 char*로 형변환하여 저장
	pc = (char*)malloc(1);
	*pc = 100;
	printf("c = %d\n", *pc);
	//free 함수를 통해 메모리 반납
	free(pc);
}
/*free 함수는 동적으로 할당된 메모리를 더 이상 사용할 필요가 없을 때 시스템에 반환하는 함수다.
만약 반납하지 않고 계속 메모리 할당만 하게 되면 메모리 누수(memory leak)가 누적되어
메모리 공간 부족 현상이 발생하게 되고 결국 프로그램 동작이 중지되는 상황이 올 수 있으므로
항상 free 함수를 사용하는 습관을 가져야 한다.*/