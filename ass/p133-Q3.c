// 매우매우 이상
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} Node;

Node* deleted_odd(Node** head1) {
	int num = 1;

	for (num = 1; num <= 4; num++) {
		if (num % 2 != 0) {
			*head1 = (*head1)->link;
		}
	}
	return (*head1);
}

int main() {

	Node* head1, * head2, * head3, * head4, * p;\

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

	p = head1;
	printf("제거 전\n");
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}

	printf("\n\n");
	printf("제거 후\n");
	deleted_odd(&head1);
	p = head1;
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	free(head1);
	free(head2);
	free(head3);
	free(head4);
	free(p);

	return 0;
}