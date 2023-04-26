#include <stdio.h>
#include <string.h>

void reverse(char* str) {
    int len = strlen(str); // 문자열의 길이 계산
    char* begin = str; // 문자열의 시작 위치를 가리키는 포인터
    char* end = str + len - 1; // 문자열의 끝 위치를 가리키는 포인터

    while (begin < end) {
        // begin 포인터가 가리키는 값을 end 포인터가 가리키는 값과 바꿈
        char temp = *begin;
        *begin = *end;
        *end = temp;

        // begin 포인터를 다음 위치로 이동하고, end 포인터를 이전 위치로 이동
        begin++;
        end--;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Original string: %s\n", str);

    reverse(str);

    printf("Reversed string: %s\n", str);
    return 0;
}
