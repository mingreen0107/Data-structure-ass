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

Node* new_node() {
	Node* new = (Node*)malloc(sizeof(Node));
	new->next = NULL;
	new->prev = NULL;

	return new;
}
void init(Node* head, Node* tail) {
	// head와 tail이 서로를 가르키도록 하는 과정
	head->next = tail;
	tail->next = head;
	head->prev = tail;
	tail->prev = head;
}
// 이어주는 노드
Node* connect_node(Node* start, char* inputName) {
	Node* new = (Node*)malloc(sizeof(Node));

	new->prev = start;
	start->next = new;
	strcpy(new->name, inputName);

	return new;
}
// 대표학생의 종이뽑기
int randset(int count) {
	int randnum = rand() % count + 1;

	return randnum;
}
// head와 tail 제외하는 함수
Node* remove_head_and_tail(Node* head, Node* tail) {
	head->next->prev = tail->prev;
	tail->prev->next = head->next;
	Node* only_data = head->next;

	return only_data;
}
// 제거 학생의 위치 제거하는 함수
void delete_node(Node* relocation) {
	relocation->next->prev = relocation->prev;
	relocation->prev->next = relocation->next;
	free(relocation);
}
// 뽑힌 사람을 기준으로 새로운 노드 생성
Node* relocation_node(Node* only_data, int count, int rand) {
	Node* relocation = only_data;
	int i;

	for (i = 1; i < rand; i++) {
		relocation = relocation->next;
	}
	return relocation;
}
// 시계 방향으로 제거하는 함수
Node* r_remove_node(Node* relocation, int picknum, int count) {
	int i;

	for (i = 0; i < picknum; i++) {
		relocation = relocation->next;
	}
	printf("\n제거 된 사람 : %s", relocation->name);
	Node* recycle = relocation->next;
	delete_node(relocation);
	printf("\n남은 학생 :");
	for (i = 0; i < count - 1; i++) {
		printf("%s   ", recycle->name);
		recycle = recycle->next;
	}
	printf("\n");
	return recycle;
}
// 반시계 방향으로 제거하는 함수
Node* l_remove_node(Node* relocation, int picknum, int count) {
	Node* recycle;
	int i;

	for (i = 0; i < picknum; i++) {
		relocation = relocation->prev;
	}
	printf("\n제거 된 사람 : %s", relocation->name);
	recycle = relocation->prev;
	delete_node(relocation);
	printf("\n남은 학생 :");
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

	printf("학생의 이름을 입력하시오. (0을 입력하면 종료)\n");
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
	printf("반장이 숫자 뽑음\n-> %d번 자리부터 재배치", rand);
	relocation = relocation_node(only_data, count, rand);

	printf("\n\n제거될 자리를 입력하시오.\n");
	scanf("%d", &picknum);

	while (count != 1) {
		relocation = r_remove_node(relocation, picknum, count);
		count--;
		if (count == 1) break;
		relocation = l_remove_node(relocation, picknum, count);
		count--;
	}
	printf("\n최종 남은 학생 : %s", relocation->name);
	free(relocation);
	return 0;
}