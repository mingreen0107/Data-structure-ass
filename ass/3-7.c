#include <stdio.h>

void main(void)
{
	char str[] = "What is Pointer?";
	char* p;
	int i;

	p = str;

	//NULL ���ڰ� �߰ߵ� ������ �ݺ��� ����Ѵ�.
	for (i = 0; p[i] != NULL; i++)
		printf("%c", p[i]);
}