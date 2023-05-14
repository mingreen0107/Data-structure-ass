#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArraytStack {
	int top;
	int stack[100];
} ArrayStack;
// 스택 초기화
void init_stack(ArrayStack* AS) {
	AS->top = -1;
}
// 항목 출력
void print_stack(ArrayStack* AS) {
	printf("top->");
	for (int i = AS->top; i >= 0; i--)
		printf("%d", AS->stack[i]);
	printf("\n");
}
int is_stack_full(ArrayStack* AS) {
	return AS->top == 99;
}
int is_stack_empty(ArrayStack* AS) {
	return AS->top == -1;
}
void push(ArrayStack* AS, int data) {
	return AS->stack[++AS->top] = data;
}
int pop(ArrayStack* AS) {
	return AS->stack[AS->top--];
}
int peek(ArrayStack* AS) {
	return AS->stack[AS->top];
}
int main() {
	ArrayStack astack;
	init_stack(&astack);
	push(&astack, 10);
	push(&astack, 20);
	push(&astack, 30);
	print_stack(&astack);
	printf("top = %d\n", peek(&astack));
	pop(&astack);
	printf("top = %d\n", peek(&astack));
	pop(&astack);
	printf("top = %d", peek(&astack));
	pop(&astack);
	pop(&astack);
}