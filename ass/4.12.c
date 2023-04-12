#include <stdio.h>

void insert_first_C(Node** p2head, Node* new) {
	if (*p2head == NULL) { // ºó ¿øÇü ¿¬°á¸®½ºÆ®¿¡ »ğÀÔ
		*p2head = new;
		new->link = new;
	}
	else { // ¸Ç ¾Õ¿¡ »ğÀÔ
		new->link = (*p2head)->link;
		(*p2head)->link = new;
	}
}

int main() {





	return 0;
}