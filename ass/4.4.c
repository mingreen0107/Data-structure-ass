#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

Node* create_node(int data) {
	Node* new = (Node*)malloc(sizeof(Node));
	if (!new) {
		printf("노드 생성에 실패하였습니다.");
		exit(1);
	}
	new->data = data;
	new->link = NULL;
	return new;
}