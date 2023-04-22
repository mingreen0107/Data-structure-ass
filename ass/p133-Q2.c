#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

Node* delete_node(Node** p2head, Node* before) {

	if (*p2head != NULL) {
		if (before == NULL)
			*p2head = (*p2head)->link;
		else
			before->link = NULL;
		return before->link;
	}
	else {
		printf("빈 연결리스트입니다.\n");
		return NULL;
	}
}
int main() {

	Node* head, * before, * deleted, * p;

	head = (Node*)malloc(sizeof(Node));
	if (!head) exit(1);
	head->data = 10;
	head->link = NULL;

	before = (Node*)malloc(sizeof(Node));
	if (!before) exit(1);
	before->data = 20;
	before->link = NULL;
	head->link = before;

	deleted = (Node*)malloc(sizeof(Node));
	if (!deleted) exit(1);
	deleted->data = 30;
	deleted->link = NULL;
	before->link = deleted;

	p = head;
	printf("제거 전\n");
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}

	p = head;
	printf("\n\n");
	printf("제거 후\n");
	delete_node(&head, before);
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	free(head);
	free(before);
	free(deleted);
	free(p);
}