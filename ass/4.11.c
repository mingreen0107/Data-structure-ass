#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* link;
} Node;

int count_nodes_C(Node* head) {
	int count = 0;
	Node* ptr = head;
	
	if (head) {
		while (ptr != head) {
			count++;
			ptr = ptr->link;
		}
	}
	return count;
}
int main() {

	Node* head = (Node*)malloc(sizeof(Node));
	int p;

	p = count_nodes_C(head);
	printf("%d", p);

	return 0;
}