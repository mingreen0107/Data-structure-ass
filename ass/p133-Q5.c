// C에 합병하는 문제
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char *data;
	struct Node* link;
	int i;
} Node;

Node* insert_node(Node** A, Node** B) {
	char C[6] = { 0, };
	int j = 0,i=0;
	do { 
		if (i == 0) {
			C[j] = (*A)->data;
			*A = (*A)->link;
			j++;
			i = 1;
		}
		else {
			C[j] = (*B)->data;
			*B = (*B)->link;
			j++;
			i = 0;
			if (j == 6) break;
		}
	} while (1);

	for (j = 0; j < 6; j++)
		printf("%c ", C[j]);
}

int main() {
	Node* a1 = (Node*)malloc(sizeof(Node));
	a1->data = 'a';
	a1->link = NULL;
	a1->i = 3;

	Node* a2 = (Node*)malloc(sizeof(Node));
	a2->data = 'c';
	a2->link = NULL;
	a2->i = 2;
	a1->link = a2;

	Node* a3 = (Node*)malloc(sizeof(Node));
	a3->data = 'e';
	a3->link = NULL;
	a3->i = 1;
	a2->link = a3;

	Node* b1 = (Node*)malloc(sizeof(Node));
	b1->data = 'q';
	b1->link = NULL;
	b1->i = 3;

	Node* b2 = (Node*)malloc(sizeof(Node));
	b2->data = 'u';
	b2->link = NULL;
	b2->i = 2;
	b1->link = b2;

	Node* b3 = (Node*)malloc(sizeof(Node));
	b3->data = 'e';
	b3->link = NULL;
	b2->i = 1;
	b2->link = b3;

	insert_node(&a1, &b1);
}