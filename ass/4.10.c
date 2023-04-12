#include <stdio.h>

Node* reverse_list(Node* head) {
	Node* new_head, * tmp_head;
	new_head = NULL; // new_head는 역순 리스트의 헤드 포인터
	while (head) {
		// tmp_head, new_head, head 순으로 차례로 오른쪽으로 이동
		tmp_head = new_head;
		new_head = head;
		head = head->link;
		new_head->link = tmp_head;
	}
	return new_head;
}