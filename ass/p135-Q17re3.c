#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node { // �̸��� �����ִ� ��� ����
	struct Node* data;
	char name[10];
	struct Node* next;
} Node;

Node* newNode(char* inputName) { // �̸��� �����ϴ� ��� ����

	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // ��忡 �̸��� �־��ֱ�
	inputname->next = NULL;

	return inputname;
}
Node* connect_node(Node* new) { // �̾��ִ� ���
	Node* connect;

	new->next = connect->next;
	connect->next = new;
}
int randset(int n) { // ��ǥ�л��� ���̻̱�
	int randpick = rand() % n+1;

	return randpick;
}
Node* relocation_node(Node** head, int picknum) { // �Լ� ���� ��ġ�� ���� ��
	Node* relocation = head;
	int i = 1;

	if (i == picknum) {
		relocation->next = (*head)->next;
		relocation->data = (*head)->data;

		return &relocation;
	}
}
Node* remain_node(Node** head, int n) { // ���ġ �Լ� ������ġ�� ���� ��ġ
	Node* headcopy = head; // �̰� ��� ����?
	// ���� �� �Լ��� �̸��� ��� ��������?
	int i = 1;

	/*if (headcopy->next == NULL)
		printf("���� ���� �л� : %s", headcopy->data);
		�̷������� ¥�� �� �ƴ��ٵ�................*/

	while (headcopy) {
		if (i == n) { // ���� �� �ڸ� �� �� ����
			headcopy->data = headcopy->next;
			
			return headcopy;
		}
		else { // �ƴ� �� ���� ���Ḯ��Ʈ�� �̵�
			i++;
			headcopy = headcopy->next;
		}
	}
}
int main() {

	Node* p, * relocation, * remain;
	char inputName[10];
	int sumstu, rand, n;

	printf("�л��� �̸��� �Է��Ͻÿ�. (0�� �Է��ϸ� ����)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = connet(&inputName);
		} // ���� ��򰡿� �̾��ִ� ��带 ����� �� ����
	}
	printf("\n�� �л����� �Է��Ͻÿ�. (��ǥ�л��� ���̻̱�)\n");
	scanf("%d", &sumstu);
	rand = randset(sumstu);
	printf("-> %d�� �ڸ����� ���ġ", rand);

	printf("���ġ �� �л����� �ڸ�\n");
	//relocation = relocation_node(&head, rand);
	while (relocation) {
		printf("%s ", relocation);
		relocation = relocation->next;
	}

	printf("\n\n���ŵ� �ڸ��� �Է��Ͻÿ�.\n");
	scanf("%d", &n);

	printf("\n���� �л� �̸�\n");
	//remain = remain_node(&head, n); // ���ġ �Լ� �ϼ��ϰ� �Ѱ��ֱ�
	while (remain) {
		printf("%s ", remain); // ���� �л� ���
		remain = remain->next;
	}
}