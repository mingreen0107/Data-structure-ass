#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct student {

	char name[100];
	int student_number;
	int score;
} student;

int get_mean(int namecount, int score) {

	int sum = 0, average = 0;
	int i;

	for (i = 0; i < namecount; i++)
	{
		sum += score;
	}
	average = sum / namecount;

	return average;
}

int get_deviation(int namecount, int average, int score) {

	double standard = 0;
	int sum = 0;
	int i;

	for (i = 0; i < namecount; i++)
	{
		sum += pow(average - score, 2);
	}
	standard = sqrt(sum / namecount);

	return standard;
}

int main() {

	student stu;
	student sir;

	strcpy(stu.name, "¼Û¹ÎÁÖ");
	stu.student_number = 20221307;
	stu.score = 100;

	strcpy(sir.name, "ÃÖÁØÇõ");
	sir.student_number = 20221376;
	sir.score = 0;

	printf("%s, %d, %d\n", stu.name, stu.student_number, stu.score);
	printf("%s, %d, %d", sir.name, sir.student_number, sir.score);

	return 0;
}