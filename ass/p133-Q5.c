#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char data;
	struct Node* link;
} Node;

Node* merge(Node** A, Node** B) {
	Node* C = (Node*)malloc(sizeof(Node));
	int i;

	for (i = 0; i < 6; i++) {
		C
	}

}

int main() {

	Node* A, * a1, * a2, * B, * b1, * b2;

	A = (Node*)malloc(sizeof(Node));
	A->data = 'a';
	A->link = NULL;

	a1 = (Node*)malloc(sizeof(Node));
	a1->data = 'c';
	a1->link = NULL;
	A->link = a1;

	a2 = (Node*)malloc(sizeof(Node));
	a2->data = 'e';
	a2->link = NULL;
	a1->link = a2;

	B = (Node*)malloc(sizeof(Node));
	B->data = 'q';
	B->link = NULL;

	b1 = (Node*)malloc(sizeof(Node));
	b1->data = 'u';
	b1->link = NULL;
	B->link = b1;

	b2 = (Node*)malloc(sizeof(Node));
	b2->data = 'e';
	b2->link = NULL;
	b1->link = b2;

	merge(&A, &B);
}