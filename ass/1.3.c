#include <stdio.h>

// �翬�� ���� �򰥷� �ߴ�. �ּڰ��� ��� �ٲ��� ���� ������ �ʴ´�.
void swap(int* p2a, int* p2b) {
	int temp;
	temp = *p2a;
	*p2a = *p2b;
	*p2b = temp;
}

int main() {
	int a, b;
	printf("��ȯ �� ���� �ΰ� �Է�\n");
	scanf("%d %d", &a, &b);
	printf("��ȯ �� : %d %d\n", a, b);
	swap(&a, &b);
	printf("��ȯ �� : %d %d", a, b);
}