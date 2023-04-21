// 경고 왜 뜸
#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

Node* delete_node(Node** p2head, Node* delete) {
	 do {
		 if ((*p2head)->link == delete) {
			 (*p2head)->link = delete->link;
			 delete->data = NULL;
		 }
		else
			*p2head = (*p2head)->link;
	 } while ((*p2head)->link != NULL);
	return *p2head;
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
	p = delete_node(&head, deleted);
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