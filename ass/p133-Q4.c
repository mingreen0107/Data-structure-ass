#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} Node;

int sum_data(Node* name, int sum) {
	int sumsum = name->data + sum;

	return sumsum;
}

int main() {

	Node* head1, * head2, * head3, * head4;
	int sum = 0;
	int i;

	head1 = (Node*)malloc(sizeof(Node));
	if (!head1) exit(1);
	head1->data = 10;
	head1->link = NULL;

	head2 = (Node*)malloc(sizeof(Node));
	if (!head2) exit(1);
	head2->data = 20;
	head2->link = NULL;
	head1->link = head2;

	head3 = (Node*)malloc(sizeof(Node));
	if (!head3) exit(1);
	head3->data = 30;
	head3->link = NULL;
	head2->link = head3;

	head4 = (Node*)malloc(sizeof(Node));
	if (!head4) exit(1);
	head4->data = 40;
	head4->link = NULL;
	head3->link = head4;

	sum = sum_data(head1, sum);
	sum = sum_data(head2, sum);
	sum = sum_data(head3, sum);
	sum = sum_data(head4, sum);

	printf("단순 연결리스트 모든 테이터 값의 합 : %d", sum);
}