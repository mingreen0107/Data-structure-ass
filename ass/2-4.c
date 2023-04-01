#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct student {

	char name[100];
	int student_number;
	int score;

} student;

//2-3�� �޸� �迭�� �ƴ� �����ͷ� �޾���
int get_mean(student* students, int N) {

	int sum = 0, average = 0;
	int i;

	for (i = 0; i < N; i++)
	{
		sum += (*(students+i)).score;
	}
	average = sum / N;

	return average;
}
int get_deviation(student* students, int average, int N) {

	double standard = 0;
	int sum = 0;
	int i;

	for (i = 0; i < N; i++)
	{
		sum += pow(average - (*(students+i)).score, 2);
	}
	standard = sqrt(sum / N);

	return standard;
}
int main() {

	student static students[1000];
	int N, a, b;
	int i;

	printf("�л����� �Է��Ͻÿ�.\n");
	scanf("%d", &N);

	printf("�л� �̸�, �й�, ������ �Է��Ͻÿ�.\n");
	for (i = 0; i < N; i++)
	{
		scanf("%s %d %d", students[i].name, &students[i].student_number, &students[i].score);
	}
	a = get_mean(students, N);
	b = get_deviation(students, a, N);

	printf("��� : %d, ǥ������ : %d", a, b);

	return 0;
}