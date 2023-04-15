#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { // 이름과 관련있는 노드 생성
	char name[10];
	struct Node* next;
} Node;

typedef struct List { // 이어주는 노드 생성
	struct List* next;
} List;

//Node* ConnectNode(Node* name, N)

Node* newNode(char* inputName) { // 이름을 저장하는 노드 생성
	
	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // 노드에 이름을 넣어주깅
	inputname->next = NULL;

	return inputname;
}

int main() {

	Node* p;
	char inputName[10];

	printf("학생의 이름을 입력하시오. (0을 입력하면 종료)\n");
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