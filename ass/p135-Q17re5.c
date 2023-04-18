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

Node* new_node() {
	Node* new = (Node*)malloc(sizeof(Node));
	new->next = NULL;
	new->prev = NULL;

	return new;
}
void init(Node* head, Node* tail) {
	// head�� tail�� ���θ� ����Ű���� �ϴ� ����
	head->next = tail;
	tail->next = head;
	head->prev = tail;
	tail->prev = head;
}
// �̾��ִ� ���
Node* connect_node(Node* start, char* inputName) {
	Node* new = (Node*)malloc(sizeof(Node));

	new->prev = start;
	start->next = new;
	strcpy(new->name, inputName);

	return new;
}
// ��ǥ�л��� ���̻̱�
int randset(int count) {
	int randnum = rand() % count + 1;

	return randnum;
}
// head�� tail �����ϴ� �Լ�
Node* remove_head_and_tail(Node* head, Node* tail) {
	head->next->prev = tail->prev;
	tail->prev->next = head->next;
	Node* only_data = head->next;

	return only_data;
}
// ���� �л��� ��ġ �����ϴ� �Լ�
void delete_node(Node* relocation) {
	relocation->next->prev = relocation->prev;
	relocation->prev->next = relocation->next;
	free(relocation);
}
// ���� ����� �������� ���ο� ��� ����
Node* relocation_node(Node* only_data, int count, int rand) {
	Node* relocation = only_data;
	int i;

	for (i = 1; i < rand; i++) {
		relocation = relocation->next;
	}
	return relocation;
}
// �ð� �������� �����ϴ� �Լ�
Node* r_remove_node(Node* relocation, int picknum, int count) {
	int i;

	for (i = 0; i < picknum; i++) {
		relocation = relocation->next;
	}
	printf("\n���� �� ��� : %s", relocation->name);
	Node* recycle = relocation->next;
	delete_node(relocation);
	printf("\n���� �л� :");
	for (i = 0; i < count - 1; i++) {
		printf("%s   ", recycle->name);
		recycle = recycle->next;
	}
	printf("\n");
	return recycle;
}
// �ݽð� �������� �����ϴ� �Լ�
Node* l_remove_node(Node* relocation, int picknum, int count) {
	Node* recycle;
	int i;

	for (i = 0; i < picknum; i++) {
		relocation = relocation->prev;
	}
	printf("\n���� �� ��� : %s", relocation->name);
	recycle = relocation->prev;
	delete_node(relocation);
	printf("\n���� �л� :");
	for (i = 0; i < count - 1; i++) {
		printf("%s   ", recycle->name);
		recycle = recycle->next;
	}
	printf("\n");
	return recycle;
}
int main() {
	Node* start, * only_data, * relocation;
	char inputName[10];
	int rand, picknum, count = 0;
	Node* head = new_node();
	Node* tail = new_node();

	init(head, tail);
	start = head;

	printf("�л��� �̸��� �Է��Ͻÿ�. (0�� �Է��ϸ� ����)\n");
	while (1) {
		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else
			start = connect_node(start, inputName);
		count++;
	}
	start->next = tail;
	tail->prev = start;
	printf("\n");

	only_data = remove_head_and_tail(head, tail);
	free(head);
	free(tail);

	rand = randset(count);
	printf("������ ���� ����\n-> %d�� �ڸ����� ���ġ", rand);
	relocation = relocation_node(only_data, count, rand);

	printf("\n\n���ŵ� �ڸ��� �Է��Ͻÿ�.\n");
	scanf("%d", &picknum);

	while (count != 1) {
		relocation = r_remove_node(relocation, picknum, count);
		count--;
		if (count == 1) break;
		relocation = l_remove_node(relocation, picknum, count);
		count--;
	}
	printf("\n���� ���� �л� : %s", relocation->name);
	free(relocation);
	return 0;
}