#include <stdio.h>
#include <memory.h>

void main()
{
	char* pc;

	//�� ������ 1����Ʈ ������ Ȯ���ϵ�, char*������ ����ȯ�ؼ� pc�� ����Ű���� �ض�
	//char�� �迭 1�� ��ŭ�� �� �޸𸮸� �Ҵ��Ͽ�
	//��ȯ���� char*�� ����ȯ�Ͽ� ����
	pc = (char*)malloc(1);
	*pc = 100;
	printf("c = %d\n", *pc);
	free(pc);
}