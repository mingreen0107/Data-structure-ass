#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

int main() {

	Node* stu1, * stu2, * stu3, * stu4;
	int n;

	stu1 = (Node*)malloc(sizeof(Node));
	if (!stu1)
		exit(1);
	stu1->data = 's';
	stu1->link = NULL;

	stu2 = (Node*)malloc(sizeof(Node));
	if (!stu2)
		exit(1);
	stu2->data = 'm';
	stu2->link = NULL;
	stu1->link = stu2;

	stu3 = (Node*)malloc(sizeof(Node));
	if (!stu3)
		exit(1);
	stu3->data = 'j';
	stu3->link = NULL;
	stu2->link = stu3;

	stu4 = (Node*)malloc(sizeof(Node));
	if (!stu4)
		exit(1);
	stu4->data = 'b';
	stu4->link = NULL;
	stu3->link = stu4;

	printf("%c - %c - %c - %c\n", stu1->data, stu1->link->data,
		stu1->link->link->data, stu1->link->link->link->data);

	scanf("%d", &n);

	if (n == 1)
		printf("%c - %c", stu1->link->link->data, stu1->link->link->link->data);
	else if (n == 2)
		printf("%c - %c", stu1->data, stu1->link->link->link->data);
	else if (n == 3)
		printf("%c - %c", stu1->link->data, stu1->link->link->link->data);
	else
		printf("%c - %c", stu1->data, stu1->link->link->data);

	free(stu1);
	free(stu2);
	free(stu3);
	free(stu4);
}