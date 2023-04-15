#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { // �̸��� �����ִ� ��� ����
	char name[10];
	struct Node* data;
	struct Node* next;
} Node;

typedef struct List { // �����ϴ� ��� ����
	int count;
	Node* head;
	Node* tail;
} List;

Node* newNode(char* inputName) { // �̸��� �����ϴ� ��� ����
	
	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // ��忡 �̸��� �־��ֱ�
	inputname->next = NULL;

	return inputname;
}
void setList(List* list) {
	list->count = 0;
}
void insert_node(Node** p2head, Node* new) {

	if (*p2head == NULL) {
		new->data = NULL;
		*p2head = new;
	}
	else {
		new->next = (*p2head)->next;
		(*p2head)->data = new;
	}
}
void connectNode(Node* p, List* list) {
	Node* new = newNode(p);

	if (list->count == 0) {
		new->next = NULL;
		new->data = list->head;
	}
	else {
		new->data = list->head;
		new->next = list->tail;
	}
	list->count++;
}


int main() {

	Node* p;
	List* list;
	char inputName[10];
	int i = 0;

	setList(&list);

	printf("�л��� �̸��� �Է��Ͻÿ�. (0�� �Է��ϸ� ����)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = newNode(inputName);
			connectNode(p, list);
			}
		}
		
	while (p)
	{
		printf("%s", p);
		p = p->next;
	}
}