#include <stdio.h>

int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str);

	; // 스택을 초기화하라
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// 만약 ch가 스페이스거나 구두점이면
		if () continue;
		ch = tolower(ch); // ch를 소문자로 변경
		; // 스택에 삽입한다.
	}
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// 만약 ch가 스페이스거나 구두점이면
		if () continue;
		ch = tolower(ch); // ch를 소문자로 변경
		chs = ; // 스택에서 문자를 꺼낸다
		if (ch != chs) return FALSE; // 실패
	}
	return TRUE; // 성공
}
