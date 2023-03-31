#include <stdio.h>
#include <string.h>

typedef struct student {

	char name[100];
	int student_number;
	int score;
} student;

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