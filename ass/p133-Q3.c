// 0이 아닌 삭제라..
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
		if (i % 2 != 0) { // 홀수번째 노드일 때
			p->data = NULL;
			p = p->link;
			i++;
		}
		else { // 짝수일 때는 단순이동
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
	printf("제거 전\n");
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}

	printf("\n\n");
	printf("제거 후\n");
	p = delete_node(a);
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	free(p);

	return 0;
}