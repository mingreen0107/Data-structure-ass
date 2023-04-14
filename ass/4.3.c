#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

int main() {

	Node* head, * temp;

	head = (Node*)malloc(sizeof(Node));
	if (!head) exit(1);
	head->data = 10;
	head->link = NULL;

	temp = (Node*)malloc(sizeof(Node));
	if (!temp) exit(1);
	temp->data = 20;
	temp->link = NULL;
	head->link = temp;

	printf("head-->%d-->%d\n", head->data, head->link->data);

	free(temp);
	free(head);
}