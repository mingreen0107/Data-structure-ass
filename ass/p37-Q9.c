#include <stdio.h>
#include <string.h>

void reverse(char* str) {
    int len = strlen(str); // ���ڿ��� ���� ���
    char* begin = str; // ���ڿ��� ���� ��ġ�� ����Ű�� ������
    char* end = str + len - 1; // ���ڿ��� �� ��ġ�� ����Ű�� ������

    while (begin < end) {
        // begin �����Ͱ� ����Ű�� ���� end �����Ͱ� ����Ű�� ���� �ٲ�
        char temp = *begin;
        *begin = *end;
        *end = temp;

        // begin �����͸� ���� ��ġ�� �̵��ϰ�, end �����͸� ���� ��ġ�� �̵�
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
