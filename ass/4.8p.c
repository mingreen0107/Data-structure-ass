#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

Node* delete_node(Node** p2head, Node* middle, Node* before, Node* deleted) {
	if (*p2head == NULL) {
		if (before == NULL)
			middle->data = NULL;
		else {
			deleted->link = before;
			(*p2head)->link = deleted;
		}
		return deleted;
	}
	else {
		printf("빈 연결리스트입니다.\n");
		return NULL;
	}
}
int main() {

	Node* head, * before, * deleted, * middle;

	head = (Node*)malloc(sizeof(Node));
	if (!head) exit(1);
	head->data = 10;
	head->link = NULL;

	middle = (Node*)malloc(sizeof(Node));
	if (!before) exit(1);
	middle->data = 20;
	middle->link = NULL;
	head->link = middle;

	before = (Node*)malloc(sizeof(Node));
	if (!before) exit(1);
	before->data = 30;
	before->link = NULL;
	middle->link = before;

	deleted = (Node*)malloc(sizeof(Node));
	if (!deleted) exit(1);
	deleted->data = NULL;
	deleted->link = NULL;

	insert_node(&head, middle, before, deleted);

	printf("%d %d", head->data, head->link->data);

	free(head);
	free(before);
	free(deleted);
}