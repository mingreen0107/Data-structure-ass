#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node { // 이름과 관련있는 노드 생성
	char name[10];
	struct Node* data;
	struct Node* next;
} Node;

Node* newNode(char* inputName) { // 이름을 저장하는 노드 생성

	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // 노드에 이름을 넣어주깅
	inputname->next = NULL;

	return inputname;
}
int randset(int n) { // 대표학생의 종이뽑기
	int randpick = rand() % n+1;

	return randpick;
}
Node* delete_node(Node** head, int n) { // 재배치 함수 시작위치와 제거 위치
	Node* headcopy = head; // 이거 어떻게 주지?
	// 제거 될 함수의 이름을 어디에 저장하지?
	int i = 1;

	while (headcopy) {
		if (i == n) { // 제거 될 자리 일 때 제거
			headcopy->data = headcopy->next;
			
			return headcopy;
		}
		else { // 아닐 시 다름 연결리스트로 이동
			i++;
			headcopy = headcopy->next;
		}
	}
}
int main() {

	Node* p;
	char inputName[10];
	int sumstu, rand, n;

	printf("학생의 이름을 입력하시오. (0을 입력하면 종료)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = newNode(inputName);
		}
	}
	printf("\n총 학생수를 입력하시오. (대표학생의 종이뽑기)\n");
	scanf("%d", &sumstu);
	rand = randset(sumstu);
	printf("-> %d번 자리부터 재배치", rand);

	printf("\n\n제거될 자리를 입력하시오.\n");
	scanf("%d", &n);
}