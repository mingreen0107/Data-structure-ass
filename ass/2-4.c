#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct student {

	char name[100];
	int student_number;
	int score;

} student;

//2-3과 달리 배열이 아닌 포인터로 받아줌
double get_mean(student* students, int N) {

	int sum = 0;
	double average = 0;
	int i;

	for (i = 0; i < N; i++)
	{
		sum += (*(students+i)).score;
	}
	average = sum / N;

	return average;
}
double get_deviation(student* students, double average, int N) {

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
	int N;
	double a, b;
	int i;

	printf("학생수를 입력하시오.\n");
	scanf("%d", &N);

	printf("학생 이름, 학번, 점수를 입력하시오.\n");
	for (i = 0; i < N; i++)
	{
		scanf("%s %d %d", students[i].name, &students[i].student_number, &students[i].score);
	}
	a = get_mean(students, N);
	b = get_deviation(students, a, N);

	printf("평균 : %.2f, 표준편차 : %.2f", a, b);

	return 0;
}