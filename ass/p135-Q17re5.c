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
void init(Node* head, Node* tail) {
	// head�� tail�� ���θ� ����Ű���� �ϴ� ����
	head->next = tail;
	head->prev = tail;
	tail->next = head;
	tail->prev = head;
}
// �̾��ִ� ���
Node* connect_node(Node* start, Node* newNode, char* inputName) {
	Node* new = (Node*)malloc(sizeof(Node));

	start->next = new;
	new->prev = start;
	strcpy(new->name, inputName);

	return new;
}
// ��ǥ�л��� ���̻̱�
int randset(int n) {
	int randpick = rand() % n + 1;

	return randpick;
}
// head�� tail �����ϴ� �Լ�
Node* remove_head_and_tail(Node* head, Node* tail) {
	Node* cycle;

	head->next->prev = tail->prev;
	tail->prev->next = head->next;
	cycle = head->next;

	return cycle;
}
// ���� ����� �������� ���ο� ��� ����
Node* relocation_node(Node* cycle, int picknum, int count) {
	Node* relocation = cycle;
	int i;

	for (i = 0; i < picknum; i++) {
		relocation = relocation->next;
	}
	printf("���� �л� : %", relocation->name);

	return relocation;
}
// ���� �л��� ��ġ �����ϴ� �Լ�
void delete_node(Node* cycle) {
	cycle->next->prev = cycle->prev;
	cycle->prev->next = cycle->next;
	free(cycle);
}
// �ð� �������� �����ϴ� �Լ�
Node* r_remove_node(Node* cycle, int picknum, int count) {
	Node* recycle;
	int i;

	for (i = 1; i < picknum; i++) {
		cycle = cycle->next;
	}
	printf("���� �� ��� : %s", cycle->name);
	recycle = cycle->next;
	delete_node(cycle);
	printf("\n���� �л� :");
	for (i = 0; i < count - 1; i++) {
		printf("%s-->", recycle->name);
		recycle = recycle->next;
	}
	printf("\n\n");

	return recycle;
}
// �ݽð� �������� �����ϴ� �Լ�
Node* l_remove_node(Node* cycle, int picknum, int count) {
	Node* recycle;
	int i;

	for (i = 1; i < picknum; i++) {
		cycle = cycle->prev;
	}
	printf("���� �� ��� : %s\n", cycle->name);
	recycle = cycle->prev;
	delete_node(cycle);
	printf("\n���� �л� :");
	for (i = 0; i < count - 1; i++) {
		printf("%s-->", recycle->name);
		recycle = recycle->next;
	}
	printf("\n\n");

	return recycle;
}
int main() {

	Node* p, * relocation, * start;
	char inputName[10];
	int sumstu, rand, n, count = 0;
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));
	head->next = head->prev = NULL;
	tail->next = tail->prev = NULL;

	init(head, tail);

	printf("�л��� �̸��� �Է��Ͻÿ�. (0�� �Է��ϸ� ����)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			start = head;
			p = newNode(inputName);
			start = connect_node(start, p, inputName);
		}
		count++;
	}
	rand = randset(count);
	printf("-> %d�� �ڸ����� ���ġ", rand);

	printf("\n\n���ŵ� �ڸ��� �Է��Ͻÿ�.\n");
	scanf("%d", &n);

	// ���� �� �л��� �̸� ����ϴ� �Լ�
	remove_node();

	// ���� �л��� ����ϴ� �Լ�
	printf("\n���� �л� �̸� : ");
	remain_node(head, tail);

	free(p);
	free(relocation);
}