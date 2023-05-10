#include <stdio.h>
#include <stdlib.h>

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
void is_stack_full(ArrayStack* AS) {
	return AS->top == 99;
}
void is_stack_empty(ArrayStack* AS) {
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
int out_prec(char op) {
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/' || op == '%') return 2;
}
char* translate_infix_to_postfix(char infix[]) {
	char token, op;
	int length = strlen(infix);
	char* postfix = (char*)malloc(sizeof(char) * length + 1);
	ArrayStack Optr;
	int idx_in = 0, idx_post = 0;

	init_stack(&Optr);
	while (idx_in < length) {
		token = infix[idx_in++];

		if ('0' <= token && token <= '9') postfix[idx_post++] = token;

		else if (token == ')')
			while ((op = pop(&Optr)) != '(') postfix[idx_post++] = op;

		else  {
			while (!is_stack_empty(&Optr) && in_prec(peek(&Optr)) >= out_prec(token))
				postfix[idx_post++] = pop(&Optr);
			push(&Optr, token);
		}
	}
	while (!is_stack_empty(&Optr)) postfix[idx_post++] = pop(&Optr);
	postfix[idx_post] = '\0';
	return postfix;
}
int main() {
	char* postfix = translate_infix_to_postfix("1+(2-3*4)/5");
	printf("after = %s", postfix);
}