#include <stdio.h>
#include <stdlib.h>

int print_sum_list(int sum, int i) {
	
}

int average(int sum, int subjectnum) {

}

int main() {
	int** subject;
	int* score;
	int subjectnum, sum = 0;
	int i, j;

	printf("������� �Է��Ͻÿ�:\n");

	scanf("%d", &subjectnum);
	subject = (int**)malloc(sizeof(int*) * subjectnum);
	for (i = 0; i < subjectnum; i++) {
		for (j = 1; j <= 5; j++) {
			subject[j] = (int*)malloc(sizeof(int) * 5);
			printf("%d��° ������ �Է��Ͻÿ�:\n", j);
			scanf("%d", score[j]);
			sum += score[j];
			print_sum_list(sum, i)
		}
	}
	
}		