#include <stdio.h>
#include <stdlib.h>

float average(float sum, float scorenum) {
	float aver = sum / scorenum;
	return aver;
}

void print_sum(int i, int sum) {
	printf("�л�%d�� ���� : %d", i, sum);
}

void print_average(int i, float aver) {
	printf("\t�л�%d�� ��� : %.1f", i, aver);
}

int main() {
	int** save_score;
	int scorenum, stunum, sum, score;
	float aver;
	int i, j;

	printf("�л��� �Է� : ");
	scanf("%d", &stunum);
	printf("����� �Է� : ");
	scanf("%d", &scorenum);
	printf("\n");

	save_score = (int**)malloc(sizeof(int*) * stunum);
	for (i = 1; i <= stunum; i++) {
		printf("[�л�%d�� ����]\n", i);

		sum = 0;

		for (j = 1; j <= scorenum; j++) {
			save_score[j] = (int*)malloc(sizeof(int) * scorenum);
			printf("����%d ���� �Է� : ", j);
			scanf("%d", save_score[j]);

			sum += *save_score[j];
		}
		print_sum(i, sum);

		aver = average(sum, scorenum);
		print_average(i, aver);

		printf("\n\n");
	}
}		