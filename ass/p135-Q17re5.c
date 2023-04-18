// 알려준 코드를 토대로 다시 짜보기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 이름과 관련있는 노드 생성
typedef struct Node {
	struct Node* prev;
	char name[10];
	struct Node* next;
} Node;

// 이름을 저장하는 노드 생성
Node* newNode(char* inputName) {
	Node* inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // 노드에 이름을 넣어주깅
	inputname->next = NULL;

	return inputname;
}
void init(Node* head, Node* tail) {
	// head와 tail이 서로를 가르키도록 하는 과정
	head->next = tail;
	head->prev = tail;
	tail->next = head;
	tail->prev = head;
}
// 이어주는 노드
Node* connect_node(Node* start, Node* newNode, char* inputName) {
	Node* new = (Node*)malloc(sizeof(Node));

	start->next = new;
	new->prev = start;
	strcpy(new->name, inputName);

	return new;
}
// 대표학생의 종이뽑기
int randset(int n) {
	int randpick = rand() % n + 1;

	return randpick;
}
// head와 tail 제외하는 함수
Node* remove_head_and_tail(Node* head, Node* tail) {
	Node* cycle;

	head->next->prev = tail->prev;
	tail->prev->next = head->next;
	cycle = head->next;

	return cycle;
}
// 뽑힌 사람을 기준으로 새로운 노드 생성
Node* relocation_node(Node* cycle, int picknum, int count) {
	Node* relocation = cycle;
	int i;

	for (i = 0; i < picknum; i++) {
		relocation = relocation->next;
	}
	printf("뽑힌 학생 : %", relocation->name);

	return relocation;
}
// 제거 학생의 위치 제거하는 함수
void delete_node(Node* cycle) {
	cycle->next->prev = cycle->prev;
	cycle->prev->next = cycle->next;
	free(cycle);
}
// 시계 방향으로 제거하는 함수
Node* r_remove_node(Node* cycle, int picknum, int count) {
	Node* recycle;
	int i;

	for (i = 1; i < picknum; i++) {
		cycle = cycle->next;
	}
	printf("제거 된 사람 : %s", cycle->name);
	recycle = cycle->next;
	delete_node(cycle);
	printf("\n남은 학생 :");
	for (i = 0; i < count - 1; i++) {
		printf("%s-->", recycle->name);
		recycle = recycle->next;
	}
	printf("\n\n");

	return recycle;
}
// 반시계 방향으로 제거하는 함수
Node* l_remove_node(Node* cycle, int picknum, int count) {
	Node* recycle;
	int i;

	for (i = 1; i < picknum; i++) {
		cycle = cycle->prev;
	}
	printf("제거 된 사람 : %s\n", cycle->name);
	recycle = cycle->prev;
	delete_node(cycle);
	printf("\n남은 학생 :");
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

	printf("학생의 이름을 입력하시오. (0을 입력하면 종료)\n");
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
	printf("-> %d번 자리부터 재배치", rand);

	printf("\n\n제거될 자리를 입력하시오.\n");
	scanf("%d", &n);

	// 제거 된 학생의 이름 출력하는 함수
	remove_node();

	// 남은 학생을 출력하는 함수
	printf("\n남은 학생 이름 : ");
	remain_node(head, tail);

	free(p);
	free(relocation);
}