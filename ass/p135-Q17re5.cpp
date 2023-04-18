// �˷��� �ڵ带 ���� �ٽ� ¥����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// �̸��� �����ִ� ��� ����
typedef struct Node {
	struct Node* prev;
	char name[10];
	struct Node* next;
} Node;

// �̸��� �����ϴ� ��� ����
Node* newNode(char* inputName) {
	Node* inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // ��忡 �̸��� �־��ֱ�
	inputname->next = NULL;

	return inputname;
}
// �ʱ�ȭ �ϴ� �Լ�
void init(Node* head, Node* tail) {
	// head�� tail�� ���θ� ����Ű���� �ϴ� ����
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}
// �̾��ִ� ���
void connect_node(Node* tail, Node* new) {
	Node* connect = new;

	tail->prev->next = connect;
	connect->prev = tail->prev;
	tail->prev = connect;
	connect->next = tail;
}
// ��ǥ�л��� ���̻̱�
int randset(int n) {
	int randpick = rand() % n + 1;

	return randpick;
}
// �Լ� ���� ��ġ�� ���� ���� ���ġ
// �̰� �����ڸ� ���� �����ʹ� ������ �� ����
Node* relocation_node(Node* head, Node* tail, int picknum) {
	Node* relocation = NULL;
	Node* p = head; // �̷��� �ִ� ���� �³�?
	int i = 1;

	if (i == picknum) {
		relocation->prev = p;
	}
	else {
		i++;
		p = p->next;
	}
	printf("���ġ �� �л����� �ڸ� :\n");
	while (relocation->next != tail) {
		printf("%s ", relocation->name);
		relocation = relocation->next;
	}
	printf("%s", relocation->name);
}
// ���� �� ��ġ�� �ִ� �л��� ����ϴ� �Լ�
Node* remove_node(Node* head, Node* tail, int picknum) {
	Node* p;
	char pickstu[10];
	int i = 0;

	p = head;
	while (p->next != tail) {
		if (i == picknum + 1) {
			strcpy(pickstu, p->name);
			break;
		}
		else {
			i++;
			p = p->next;
		}
	}
	if (p->next == tail) {
		printf("���� ���� �л� : %s", p->next); // ���� ��� �Ѱ��������? 
	}
	else {
		printf("���� �� �л� : %s", pickstu);
	}
	free(p);
}
// ���� �л����� ����ϴ� �Լ�
Node* remain_node(Node* head, Node* tail) {
	Node* p;
	p = head;

	while (p->next != tail) {
		printf("%s ", p->name);
		p = p->next;
	}
	printf("%s", p->name);
	free(p);
}
int main() {

	Node* p, * relocation;
	char inputName[10];
	int sumstu, rand, n, count = 0;
	Node* head;
	Node* tail;
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));

	init(head, tail);

	printf("�л��� �̸��� �Է��Ͻÿ�. (0�� �Է��ϸ� ����)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = newNode(inputName);
			connect_node(head, tail, p);
		}
		count++;
	}
	rand = randset(count);
	printf("-> %d�� �ڸ����� ���ġ", rand);

	printf("���ġ �� �л����� �ڸ�\n");
	relocation = relocation_node(head, tail, rand);
	while (relocation) {
		printf("%s ", relocation);
		relocation = relocation->next;
	}

	printf("\n\n���ŵ� �ڸ��� �Է��Ͻÿ�.\n");
	scanf("%d", &n);

	// ���� �� �л��� �̸� ����ϴ� �Լ�
	remove_node(head, tail, rand);

	// ���� �л��� ����ϴ� �Լ�
	printf("\n���� �л� �̸� : ");
	remain_node(head, tail);

	free(p);
	free(relocation);
}