// 0�� �ƴ� ������..
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} Node;

Node* delete_node(Node* a) {
	Node* p = (Node*)malloc(sizeof(Node));
	int i = 1;

	p = a;
	while (i < 5) {
		if (i % 2 != 0) { // Ȧ����° ����� ��
			p->data = NULL;
			p = p->link;
			i++;
		}
		else { // ¦���� ���� �ܼ��̵�
			p = p->link;
			i++;
		}
	}
	return a;
}

int main() {

	Node* a, * b, * c, * d, * p;
	int i;

	a = (Node*)malloc(sizeof(Node));
	a->data = 1;
	a->link = NULL;

	b = (Node*)malloc(sizeof(Node));
	b->data = 2;
	b->link = NULL;
	a->link = b;

	c = (Node*)malloc(sizeof(Node));
	c->data = 3;
	c->link = NULL;
	b->link = c;

	d = (Node*)malloc(sizeof(Node));
	d->data = 4;
	d->link = NULL;
	c->link = d;

	p = (Node*)malloc(sizeof(Node));
	p = a;
	printf("���� ��\n");
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}

	printf("\n\n");
	printf("���� ��\n");
	p = delete_node(a);
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	free(p);

	return 0;
}