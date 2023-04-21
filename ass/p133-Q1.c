#include <stdio.h>
#include <stdlib.h>

float average(float sum, float scorenum) {
	float aver = sum / scorenum;
	return aver;
}

void print_sum(int i, int sum) {
	printf("학생%d의 총점 : %d", i, sum);
}

void print_average(int i, float aver) {
	printf("\t학생%d의 평균 : %.1f", i, aver);
}

int main() {
	int** save_score;
	int scorenum, stunum, sum, score;
	float aver;
	int i, j;

	printf("학생수 입력 : ");
	scanf("%d", &stunum);
	printf("과목수 입력 : ");
	scanf("%d", &scorenum);
	printf("\n");

	save_score = (int**)malloc(sizeof(int*) * stunum);
	for (i = 1; i <= stunum; i++) {
		printf("[학생%d의 성적]\n", i);

		sum = 0;

		for (j = 1; j <= scorenum; j++) {
			save_score[j] = (int*)malloc(sizeof(int) * scorenum);
			printf("과목%d 점수 입력 : ", j);
			scanf("%d", save_score[j]);

			sum += *save_score[j];
		}
		print_sum(i, sum);

		aver = average(sum, scorenum);
		print_average(i, aver);

		printf("\n\n");
	}
}		