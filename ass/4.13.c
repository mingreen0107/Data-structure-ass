#include <stdio.h>

void insert_last_C(Node** p2head, Node* new) {
	if (*p2head == NULL) { // �� ���� ���Ḯ��Ʈ�� ����
		*p2head = new;
		new->link = new;
	}
	else { // �� �������� ����
		new->link = (*p2head)->link;
		(*p2head)->link = new;
		*p2head = new; // insert_first_C�� ���⸸ �߰�
	}
}
int main() {





	return 0;
}