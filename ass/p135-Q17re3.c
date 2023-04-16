#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node { // 이름과 관련있는 노드 생성
	struct Node* data;
	char name[10];
	struct Node* next;
} Node;

Node* newNode(char* inputName) { // 이름을 저장하는 노드 생성

	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // 노드에 이름을 넣어주깅
	inputname->next = NULL;

	return inputname;
}
Node* connect_node(Node* new) { // 이어주는 노드
	Node* connect;

	new->next = connect->next;
	connect->next = new;
}
int randset(int n) { // 대표학생의 종이뽑기
	int randpick = rand() % n+1;

	return randpick;
}
Node* relocation_node(Node** head, int picknum) { // 함수 시작 위치와 뽑은 수
	Node* relocation = head;
	int i = 1;

	if (i == picknum) {
		relocation->next = (*head)->next;
		relocation->data = (*head)->data;

		return &relocation;
	}
}
Node* remain_node(Node** head, int n) { // 재배치 함수 시작위치와 제거 위치
	Node* headcopy = head; // 이거 어떻게 주지?
	// 제거 될 함수의 이름을 어디에 저장하지?
	int i = 1;

	/*if (headcopy->next == NULL)
		printf("최종 남은 학생 : %s", headcopy->data);
		이런식으로 짜는 게 아닐텐데................*/

	while (headcopy) {
		if (i == n) { // 제거 될 자리 일 때 제거
			headcopy->data = headcopy->next;
			
			return headcopy;
		}
		else { // 아닐 시 다음 연결리스트로 이동
			i++;
			headcopy = headcopy->next;
		}
	}
}
int main() {

	Node* p, * relocation, * remain;
	char inputName[10];
	int sumstu, rand, n;

	printf("학생의 이름을 입력하시오. (0을 입력하면 종료)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = connet(&inputName);
		} // 여기 어딘가에 이어주는 노드를 써야할 것 같옹
	}
	printf("\n총 학생수를 입력하시오. (대표학생의 종이뽑기)\n");
	scanf("%d", &sumstu);
	rand = randset(sumstu);
	printf("-> %d번 자리부터 재배치", rand);

	printf("재배치 후 학생들의 자리\n");
	//relocation = relocation_node(&head, rand);
	while (relocation) {
		printf("%s ", relocation);
		relocation = relocation->next;
	}

	printf("\n\n제거될 자리를 입력하시오.\n");
	scanf("%d", &n);

	printf("\n남은 학생 이름\n");
	//remain = remain_node(&head, n); // 재배치 함수 완성하고 넘겨주기
	while (remain) {
		printf("%s ", remain); // 남은 학생 출력
		remain = remain->next;
	}
}