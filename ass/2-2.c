#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct student {

	char name[100];
	int student_number;
	int score;

} student;

int main() {

	student static students[1000];
	int N;
	int i;

	printf("�л����� �Է��Ͻÿ�.\n");
	scanf("%d", &N);

	printf("�л� �̸�, �й�, ������ �Է��Ͻÿ�.\n");
	for (i = 0; i < N; i++)
	{
		scanf("%s %d %d\n", students[i].name, &students[i].student_number, &students[i].score);
	}
	return 0;
}