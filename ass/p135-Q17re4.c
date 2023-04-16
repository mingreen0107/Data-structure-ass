// ���߿���� Ǯ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// �̸��� �����ִ� ��� ����
typedef struct Node { 
	struct Node* data;
	char name[10];
	struct Node* next;
} Node;
Node* head;
Node* tail;

// �̸��� �����ϴ� ��� ����
Node* newNode(char* inputName) { 

	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // ��忡 �̸��� �־��ֱ�
	inputname->next = NULL;

	return inputname;
}
// ��� �Լ�
void print() { 
	struct Node* p;
	p = head;

	while (p->next != tail) {
		printf("%s-->", p->name);
		p = p->next;
	}
	printf("%s", p->name);
}
void init() {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->name = NULL; // �ʱ�ȭ �ϴ� ����?
	tail->name = NULL;

	head->next = tail;
	head->data = head;
	tail->next = tail;
	tail->data = head;
}
// �̾��ִ� ���
Node* connect_node(Node* new) { 
	Node* connect = newNode(new);
	Node* p;
	p = tail;
	p->data->next = connect;
	connect->data = p->data;
	p->data = connect;
	connect->next = p;
}
// ��ǥ�л��� ���̻̱�
int randset(int n) { 
	int randpick = rand() % n + 1;

	return randpick;
}
// �Լ� ���� ��ġ�� ���� ���� ���ġ
Node* relocation_node(Node** head, int picknum) { 
	Node* relocation = head;
	int i = 1;

	if (i == picknum) {
		relocation->next = (*head)->next;
		relocation->data = (*head)->data;

		return &relocation;
	}
}
// ���� �� ��ġ�� �ִ� �л��� pickstu�� �����ϴ� �Լ�
Node* remove_node(Node** p2head, int picknum) {
	Node* p, * q;
	char pickstu[10];
	int i = 0;
	
	p = head->next;
	while (i == picknum+1) {
		p = p->next;
		i++;
	}
	strcpy(pickstu, p->name);

	return pickstu;
}
// ���� �л����� ����ϴ� �Լ�
Node* remain_node(Node** p2head, int picknum) {
	Node* p, * q;
	int i = 0;

	p = head->next;
	// �����ϴ� �Լ�
	q = head->next;
	while (q->next != tail) {
		if (q->data == p->data) {
			q->next->data = q->data;
			q->data->next = p->next;
			free(q);
			return;
		}
		q = q->next;
	}
	return &q;
}
int main() {

	Node* p, * relocation, * remain, * pickstu;
	char inputName[10];
	int sumstu, rand, n;

	printf("�л��� �̸��� �Է��Ͻÿ�. (0�� �Է��ϸ� ����)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = connet(&inputName);
			connect_node(p);
		}
	}
	printf("\n�� �л����� �Է��Ͻÿ�. (��ǥ�л��� ���̻̱�)\n");
	scanf("%d", &sumstu);
	rand = randset(sumstu);
	printf("-> %d�� �ڸ����� ���ġ", rand);

	printf("���ġ �� �л����� �ڸ�\n");
	relocation = relocation_node(&head, rand);
	while (relocation) {
		printf("%s ", relocation);
		relocation = relocation->next;
	}

	printf("\n\n���ŵ� �ڸ��� �Է��Ͻÿ�.\n");
	scanf("%d", &n);

	// ���� �� �л��� �̸� ����ϴ� �Լ�
	pickstu = remove_node(&head, rand);
	printf("���� �� �л� : %s", pickstu);

	// ���� �л��� ����ϴ� �Լ�
	printf("\n���� �л� �̸�\n");
	remain = remain_node(&head, n);
	while (remain) {
		printf("%s ", remain);
		remain = remain->next;
	}
}