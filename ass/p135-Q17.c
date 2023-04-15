#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { // �̸��� �����ִ� ��� ����
	char name[10];
	struct Node* next;
} Node;

typedef struct List { // �̾��ִ� ��� ����
	struct List* next;
} List;

//Node* ConnectNode(Node* name, N)

Node* newNode(char* inputName) { // �̸��� �����ϴ� ��� ����
	
	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // ��忡 �̸��� �־��ֱ�
	inputname->next = NULL;

	return inputname;
}

int main() {

	Node* p;
	char inputName[10];

	printf("�л��� �̸��� �Է��Ͻÿ�. (0�� �Է��ϸ� ����)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = newNode(inputName);
			
			while (p) {
				printf("%s ", p->name);
				p = p->next;
			}
		}
		

	}
}