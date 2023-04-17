// 단일연결 이어주는 문제
#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

Node* concatenate_lists(Node* head1, Node* head2) {

	Node* last;

	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		last = head1;
		while (last->link)
			last = last->link;
		last->link = head2;
		return head1;
	}
}
int main() {

	Node* head1, * head2, *data1, *data2, *p;

	head1 = (Node*)malloc(sizeof(Node));
	if (!head1) exit(1);
	head1->data = 10;
	head1->link = NULL;

	data1 = (Node*)malloc(sizeof(Node));
	if (!data1) exit(1);
	data1->data = 20;
	data1->link = NULL;
	head1->link = data1;

	head2 = (Node*)malloc(sizeof(Node));
	if (!head2) exit(1);
	head2->data = 30;
	head2->link = NULL;

	data2 = (Node*)malloc(sizeof(Node));
	if (!data2) exit(1);
	data2->data = 40;
	data2->link = NULL;
	head2->link = data2;

	concatenate_lists(head1, head2);

	p = head1;

	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	free(head1);
	free(head2);
	free(data1);
	free(data2);
	free(p);
}