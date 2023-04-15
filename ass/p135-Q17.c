#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { // 이름과 관련있는 노드 생성
	char name[10];
	struct Node* data;
	struct Node* next;
} Node;

typedef struct List { // 연결하는 노드 생성
	int count;
	Node* head;
	Node* tail;
} List;

Node* newNode(char* inputName) { // 이름을 저장하는 노드 생성
	
	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // 노드에 이름을 넣어주깅
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

	printf("학생의 이름을 입력하시오. (0을 입력하면 종료)\n");
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