// ȸ�� ������, �����̽�, ��ҹ��� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct ArrayStack {
	int top;
	char stack[100];
} ArratStack;

void init_stack(ArrayStack* AS) {
	AS->top = -1;
}
int peek(ArrayStack* AS) {
	return AS->stack[AS->top];
}
void push(ArrayStack* AS, int data) {
	return AS->stack[++AS->top] = data;
}
// ȸ���̸� TRUE ��ȯ �ƴϸ� FALSE�� ��ȯ�Ѵ�.
int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str);

	init_stack(&s); // ������ �ʱ�ȭ�϶�
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if (ch ==' ' || ch == top) continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		push(&s, ch); // ���ÿ� �����Ѵ�.
	}
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if (ch == ' ' || ch == top) continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		chs = peek(&s); // ���ÿ��� ���ڸ� ������
		if (ch != chs) return FALSE; // ����
	}
	return TRUE; // ����
}

int main()
{

	
	
	return 0;
}
