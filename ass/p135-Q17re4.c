// 이중연결로 풀어보기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 이름과 관련있는 노드 생성
typedef struct Node { 
	struct Node* data;
	char name[10];
	struct Node* next;
} Node;
Node* head;
Node* tail;

// 이름을 저장하는 노드 생성
Node* newNode(char* inputName) { 

	Node* inputname;

	inputname = (Node*)malloc(sizeof(Node));
	strcpy(inputname->name, inputName); // 노드에 이름을 넣어주깅
	inputname->next = NULL;

	return inputname;
}
// 출력 함수
void print() { 
	struct Node* p;
	p = head;

	while (p->next != tail) {
		printf("%s-->", p->name);
		p = p->next;
	}
	printf("%s", p->name);
}
void init() {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->name = NULL; // 초기화 하는 법은?
	tail->name = NULL;

	head->next = tail;
	head->data = head;
	tail->next = tail;
	tail->data = head;
}
// 이어주는 노드
Node* connect_node(Node* new) { 
	Node* connect = newNode(new);
	Node* p;
	p = tail;
	p->data->next = connect;
	connect->data = p->data;
	p->data = connect;
	connect->next = p;
}
// 대표학생의 종이뽑기
int randset(int n) { 
	int randpick = rand() % n + 1;

	return randpick;
}
// 함수 시작 위치와 뽑은 수로 재배치
Node* relocation_node(Node** head, int picknum) { 
	Node* relocation = head;
	int i = 1;

	if (i == picknum) {
		relocation->next = (*head)->next;
		relocation->data = (*head)->data;

		return &relocation;
	}
}
// 제거 될 위치에 있는 학생을 pickstu에 저장하는 함수
Node* remove_node(Node** p2head, int picknum) {
	Node* p, * q;
	char pickstu[10];
	int i = 0;
	
	p = head->next;
	while (i == picknum+1) {
		p = p->next;
		i++;
	}
	strcpy(pickstu, p->name);

	return pickstu;
}
// 남은 학생들을 출력하는 함수
Node* remain_node(Node** p2head, int picknum) {
	Node* p, * q;
	int i = 0;

	p = head->next;
	// 제거하는 함수
	q = head->next;
	while (q->next != tail) {
		if (q->data == p->data) {
			q->next->data = q->data;
			q->data->next = p->next;
			free(q);
			return;
		}
		q = q->next;
	}
	return &q;
}
int main() {

	Node* p, * relocation, * remain, * pickstu;
	char inputName[10];
	int sumstu, rand, n;

	printf("학생의 이름을 입력하시오. (0을 입력하면 종료)\n");
	while (1) {

		scanf("%s", inputName);

		if (inputName[0] == '0')
			break;
		else {
			p = connet(&inputName);
			connect_node(p);
		}
	}
	printf("\n총 학생수를 입력하시오. (대표학생의 종이뽑기)\n");
	scanf("%d", &sumstu);
	rand = randset(sumstu);
	printf("-> %d번 자리부터 재배치", rand);

	printf("재배치 후 학생들의 자리\n");
	relocation = relocation_node(&head, rand);
	while (relocation) {
		printf("%s ", relocation);
		relocation = relocation->next;
	}

	printf("\n\n제거될 자리를 입력하시오.\n");
	scanf("%d", &n);

	// 제거 된 학생의 이름 출력하는 함수
	pickstu = remove_node(&head, rand);
	printf("제거 된 학생 : %s", pickstu);

	// 남은 학생을 출력하는 함수
	printf("\n남은 학생 이름\n");
	remain = remain_node(&head, n);
	while (remain) {
		printf("%s ", remain);
		remain = remain->next;
	}
}