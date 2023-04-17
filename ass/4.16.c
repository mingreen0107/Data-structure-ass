#define DataType Movie
#include <stdio.h>
#include <stdlib.h>

// ��ȭ ������ �����ϴ� ����ü Movie ����
typedef struct Movie {
	char title[50];
	int release;
	int viewers;
} Movie;

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

typedef struct LinkedB0_C {
	int length;
	Node* tail;
} LinkedB0_C;

Node* create_node(DataType data) {
	Node* new = (Node*)malloc(sizeof(Node));
	if (!new) {
		printf("��� ���� ����");
		exit(1);
	}
	new->data = data;
	new->link = NULL;
	return new;
}

void init_list(LinkedB0_C* B0) { // �ʱ�ȭ�ټ�
	B0->length = 0;
	B0->tail = NULL;
}

void print_list(LinkedB0_C* B0) {
	Node* ptr = B0->tail; // Movie�� ������ �Ѱ���
	int j = 1;
	for (int i = 1; i <= B0->length; i++) {
		ptr = ptr->link; // �굵 �ʱ�ȭ����
		printf("%d) ����=%s, ��������=%d, ������=%d\n",
			j, ptr->data.title, ptr->data.release, ptr->data.viewers);
		j++;
	}
}

void insert_node_last(LinkedB0_C* B0, Node* new) {
	B0->length++; 
	if (B0->tail == NULL) { // �� ���Ḯ��Ʈ
		B0->tail = new;
		new->link = new;
	}
	else { // ������ ����
		new->link = B0->tail->link;
		B0->tail->link = new; 
		B0->tail = new;
	}
}

LinkedB0_C merge_B0(LinkedB0_C* a, LinkedB0_C* b) {
	LinkedB0_C c;
	Node* p2a = a->tail, * p2b = b->tail;
	int num_a = a->length, num_b = b->length;

	init_list(&c);
	if (p2a) p2a = p2a->link; // ���� ����� �߱������� ����?
	if (p2b) p2b = p2b->link; 

	while (num_a != 0 && num_b != 0) {
		if (p2a->data.viewers >= p2b->data.viewers) {
			insert_node_last(&c, create_node(p2a->data));
			p2a = p2a->link;
			num_a--;
		}
		else {
			insert_node_last(&c, create_node(p2b->data));
			p2b = p2b->link;
			num_b--;
		}
	}
	while (num_a != 0) {
		insert_node_last(&c, create_node(p2a->data));
		p2a = p2a->link;
		num_a--;
	}
	while (num_b != 0) {
		insert_node_last(&c, create_node(p2b->data));
		p2b = p2b->link;
		num_b--;
	}
	return c;
}

int main() {
	LinkedB0_C domestic, foreign;
	Movie m1 = { "��", 2014, 1761 };
	Movie m2 = { "���׶�", 2015, 1341 };
	Movie m3 = { "���ϵ�", 2012, 1298 };
	Movie m4 = { "�ϻ�", 2015, 1270 };
	Movie m5 = { "�ƹ�Ÿ", 2009, 1333 };
	Movie m6 = { "���ͽ��ڶ�", 2014, 1030 };
	Movie m7 = { "�ܿ�ձ�", 2014, 1029 };

	init_list(&domestic);
	init_list(&foreign);

	insert_node_last(&domestic, create_node(m1));
	insert_node_last(&domestic, create_node(m2));
	insert_node_last(&domestic, create_node(m3));
	insert_node_last(&domestic, create_node(m4));

	insert_node_last(&foreign, create_node(m5));
	insert_node_last(&foreign, create_node(m6));
	insert_node_last(&foreign, create_node(m7));

	LinkedB0_C merged = merge_B0(&domestic, &foreign);
	print_list(&merged);
}