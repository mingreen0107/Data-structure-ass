#include <stdio.h>

void insert_last_C(Node** p2head, Node* new) {
	if (*p2head == NULL) { // 빈 원형 연결리스트에 삽입
		*p2head = new;
		new->link = new;
	}
	else { // 맨 마지막에 삽입
		new->link = (*p2head)->link;
		(*p2head)->link = new;
		*p2head = new; // insert_first_C에 여기만 추가
	}
}
int main() {





	return 0;
}