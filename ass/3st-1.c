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
		// ch를 소문자로 변경 후 스택에 삽입
		ch = tolower(ch); 
	}
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// 만약 ch가 스페이스거나 구두점이면
		if () continue;
		// ch를 소문자로 변경
		ch = tolower(ch); 
		if (ch != chs) return FALSE; // 실패
	}
	return TRUE; // 성공
}
