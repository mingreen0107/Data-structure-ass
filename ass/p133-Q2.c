// ��� �� ��
#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

Node* delete_node(Node** p2head, Node* deleted) {
	if ((*p2head)->link == deleted) 
		(*p2head)->link = deleted->link;
	else
		*p2head = (*p2head)->link;

	return deleted;
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
	printf("���� ��\n");
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	
	printf("\n\n");
	printf("���� ��\n");
	delete_node(&head, deleted);
	p = head;
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