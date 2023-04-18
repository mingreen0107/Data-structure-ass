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
// 초기화 하는 함수
void init(Node* head, Node* tail) {
	// head와 tail이 서로를 가르키도록 하는 과정
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}
// 이어주는 노드
void connect_node(Node* tail, Node* new) {
	Node* connect = new;

	tail->prev->next = connect;
	connect->prev = tail->prev;
	tail->prev = connect;
	connect->next = tail;
}
// 대표학생의 종이뽑기
int randset(int n) {
	int randpick = rand() % n + 1;

	return randpick;
}
// 함수 시작 위치와 뽑은 수로 재배치
// 이게 뽑은자리 전의 데이터는 가져올 수 없음
Node* relocation_node(Node* head, Node* tail, int picknum) {
	Node* relocation = NULL;
	Node* p = head; // 이렇게 주는 것이 맞나?
	int i = 1;

	if (i == picknum) {
		relocation->prev = p;
	}
	else {
		i++;
		p = p->next;
	}
	printf("재배치 후 학생들의 자리 :\n");
	while (relocation->next != tail) {
		printf("%s ", relocation->name);
		relocation = relocation->next;
	}
	printf("%s", relocation->name);
}
// 제거 될 위치에 있는 학생을 출력하는 함수
Node* remove_node(Node* head, Node* tail, int picknum) {
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
		printf("최종 남은 학생 : %s", p->next); // 값을 어떻게 넘겨줘야하지? 
	}
	else {
		printf("제거 된 학생 : %s", pickstu);
	}
	free(p);
}
// 남은 학생들을 출력하는 함수
Node* remain_node(Node* head, Node* tail) {
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
	int sumstu, rand, n, count = 0;
	Node* head;
	Node* tail;
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));

	init(head, tail);

	printf("학생의 이름을 입력하시오. (0을 입력하면 종료)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = newNode(inputName);
			connect_node(head, tail, p);
		}
		count++;
	}
	rand = randset(count);
	printf("-> %d번 자리부터 재배치", rand);

	printf("재배치 후 학생들의 자리\n");
	relocation = relocation_node(head, tail, rand);
	while (relocation) {
		printf("%s ", relocation);
		relocation = relocation->next;
	}

	printf("\n\n제거될 자리를 입력하시오.\n");
	scanf("%d", &n);

	// 제거 된 학생의 이름 출력하는 함수
	remove_node(head, tail, rand);

	// 남은 학생을 출력하는 함수
	printf("\n남은 학생 이름 : ");
	remain_node(head, tail);

	free(p);
	free(relocation);
}