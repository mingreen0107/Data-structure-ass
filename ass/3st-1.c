// ȸ�� ������, �����̽�, ��ҹ��� ����
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack {
	int top;
	int stack[100];
} ArratStack;

// ȸ���̸� TRUE ��ȯ �ƴϸ� FALSE�� ��ȯ�Ѵ�.
int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str);

	; // ������ �ʱ�ȭ�϶�
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if () continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		; // ���ÿ� �����Ѵ�.
	}
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if () continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		chs = ; // ���ÿ��� ���ڸ� ������
		if (ch != chs) return FALSE; // ����
	}
	return TRUE; // ����
}

int main()
{

	
	
	return 0;
}
