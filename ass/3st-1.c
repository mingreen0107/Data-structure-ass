#include <stdio.h>

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
		// ch�� �ҹ��ڷ� ���� �� ���ÿ� ����
		ch = tolower(ch); 
	}
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if () continue;
		// ch�� �ҹ��ڷ� ����
		ch = tolower(ch); 
		if (ch != chs) return FALSE; // ����
	}
	return TRUE; // ����
}
