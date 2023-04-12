#include <stdio.h>

Node* reverse_list(Node* head) {
	Node* new_head, * tmp_head;
	new_head = NULL; // new_head�� ���� ����Ʈ�� ��� ������
	while (head) {
		// tmp_head, new_head, head ������ ���ʷ� ���������� �̵�
		tmp_head = new_head;
		new_head = head;
		head = head->link;
		new_head->link = tmp_head;
	}
	return new_head;
}