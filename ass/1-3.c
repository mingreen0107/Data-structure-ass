#include <stdio.h>
//rand()�Լ��� ����ϱ� ���� �������
#include <stdlib.h>

int main() {

	int random[10] = { 0 };
	int min = 10, max = 0;
	int i;

	for (i = 0; i < 10; i++)
	{
		//rand() �Լ��� ����ִ� ������ ũ�� ������
		//rnad() �Լ��� ���� ������ �����ϰ� �� ���ڸ� 10���� ���� �������� ������ ����
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
	//rand()�Լ��� ���� random���� �������� ���� �ƴ϶�
	//��ǻ���� ������ rand()�Լ��� ������ ������ �׻� ���� ������ ����
	printf("�ִ밪 : %d\n�ּҰ� : %d", max, min);

	//���� ������ �ٸ��� �ϰ� �ʹٸ�
	//srand(time(NULL));�� ����ϸ� �ȴ�.
	//�� �Լ��� 1�� ������ �Ź� �ٸ� �õ尪�� ������ rand()�Լ��� ȣ���ϴ� �Լ���.

	return 0;
}
