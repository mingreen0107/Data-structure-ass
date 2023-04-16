#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node { // �̸��� �����ִ� ��� ����
	char name[10];
	struct Node* data;
	struct Node* next;
} Node;

Node* newNode(char* inputName) { // �̸��� �����ϴ� ��� ����

	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // ��忡 �̸��� �־��ֱ�
	inputname->next = NULL;

	return inputname;
}
int randset(int n) { // ��ǥ�л��� ���̻̱�
	int randpick = rand() % n+1;

	return randpick;
}
Node* delete_node(Node** head, int n) { // ���ġ �Լ� ������ġ�� ���� ��ġ
	Node* headcopy = head; // �̰� ��� ����?
	// ���� �� �Լ��� �̸��� ��� ��������?
	int i = 1;

	while (headcopy) {
		if (i == n) { // ���� �� �ڸ� �� �� ����
			headcopy->data = headcopy->next;
			
			return headcopy;
		}
		else { // �ƴ� �� �ٸ� ���Ḯ��Ʈ�� �̵�
			i++;
			headcopy = headcopy->next;
		}
	}
}
int main() {

	Node* p;
	char inputName[10];
	int sumstu, rand, n;

	printf("�л��� �̸��� �Է��Ͻÿ�. (0�� �Է��ϸ� ����)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = newNode(inputName);
		}
	}
	printf("\n�� �л����� �Է��Ͻÿ�. (��ǥ�л��� ���̻̱�)\n");
	scanf("%d", &sumstu);
	rand = randset(sumstu);
	printf("-> %d�� �ڸ����� ���ġ", rand);

	printf("\n\n���ŵ� �ڸ��� �Է��Ͻÿ�.\n");
	scanf("%d", &n);
}