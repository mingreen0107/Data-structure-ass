#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

Node* concatenate_lists(Node* p2head, Node* before, Node* deleted) {
	if (*p2head == NULL) {
		if (before == NULL)
			*p2head = (*p2head)->link;
		else before->link = deleted->link;
		return deleted;
	}
	else {
		printf("빈 연결리스트입니다.\n");
		return NULL;
	}
}
int main() {

	Node* head, * before, * deleted;

	head = (Node*)malloc(sizeof(Node));
	if (!head) exit(1);
	head->data = 10;
	head->link = NULL;

	before = (Node*)malloc(sizeof(Node));
	if (!before) exit(1);
	before->data = 20;
	before->link = NULL;

	deleted = (Node*)malloc(sizeof(Node));
	if (!deleted) exit(1);
	deleted->data = 15;
	deleted->link = NULL;

	insert_node(&head, before, deleted);

	printf("%d %d %d", head->data, head->link->data, head->link->link->data);

	free(head);
	free(before);
	free(deleted);
}