// ���߿��Ḯ��Ʈ�� Ǯ���
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
Node* head;
Node* tail;

// �̸��� �����ϴ� ��� ����
Node* newNode(char *inputName) {
	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	inputname = (char*)malloc(strlen(inputName) + 1);
	strcpy(inputname->name, inputName); // ��忡 �̸��� �־��ֱ�
	inputname->next = NULL;

	return inputname;
}
// �ʱ�ȭ �ϴ� �Լ�
void init() {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	*head->name = 'NULL'; // �ʱ�ȭ �ϴ� ���� �̰� ��za?
	*tail->name = 'NULL'; // prev�� next�� �� �ʱ�ȭ�� �� �ص� �ɱ�?

	// head�� tail�� ���θ� ����Ű���� �ϴ� ����
	head->next = tail; 
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}
// �̾��ִ� ���
void connect_node(Node* new) { 
	Node* connect = newNode(new);
	Node* p;
	p = tail;

	p->prev->next = connect;
	connect->prev = p->prev;
	p->prev = connect;
	connect->next = p;
}
// ��ǥ�л��� ���̻̱�
int randset(int n) { 
	int randpick = rand() % n + 1;

	return randpick;
}
// �Լ� ���� ��ġ�� ���� ���� ���ġ
// �̰� �����ڸ� ���� �����ʹ� ������ �� ����
Node* relocation_node(Node** p2head, int picknum) {
	Node* relocation;
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
Node* remove_node(int picknum) {
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
		printf("���� ���� �л� : %s", ?); // ���� ��� �Ѱ��������?
	}
	else {
		printf("���� �� �л� : %s", pickstu);
	}
	free(p);
}
// ���� �л����� ����ϴ� �Լ�
Node* remain_node(Node** p2head) {
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
	int sumstu, rand, n;

	printf("�л��� �̸��� �Է��Ͻÿ�. (0�� �Է��ϸ� ����)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = newNode(inputName);
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
	remove_node(rand);

	// ���� �л��� ����ϴ� �Լ�
	printf("\n���� �л� �̸� : ");
	remain_node(&head);

	free(p);
	free(relocation);
}