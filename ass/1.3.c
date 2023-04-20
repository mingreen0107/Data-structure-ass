#include <stdio.h>

// 당연한 것을 헷갈려 했다. 주솟값을 줘야 바꿔준 값이 날라가지 않는다.
void swap(int* p2a, int* p2b) {
	int temp;
	temp = *p2a;
	*p2a = *p2b;
	*p2b = temp;
}

int main() {
	int a, b;
	printf("교환 할 숫자 두개 입력\n");
	scanf("%d %d", &a, &b);
	printf("교환 전 : %d %d\n", a, b);
	swap(&a, &b);
	printf("교환 후 : %d %d", a, b);
}