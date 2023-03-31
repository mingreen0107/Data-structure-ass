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

	printf("학생수를 입력하시오.\n");
	scanf("%d", &N);

	printf("학생 이름, 학번, 점수를 입력하시오.\n");
	for (i = 0; i < N; i++)
	{
		scanf("%s %d %d\n", students[i].name, &students[i].student_number, &students[i].score);
	}
	return 0;
}