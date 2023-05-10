#include <stdio.h>
#include <stdlib.h>

typedef struct Snode {
	int data;
	struct Snode* link;
} Snode;

typedef struct Linkedstack {
	Snode* top;
} LinkedStack;
// ÃÊ±âÈ­
void init_stack(LinkedStack* LS) {
	LS->top = NULL;
}
void print_stack(LinkedStack* LS) {
	printf("top");
	for (Snode* ptr = LS->top; ptr; ptr = ptr->link)
		printf("->%d", ptr->data);
	printf("\n");
}
void push(LinkedStack* LS, int data) {
	Snode* new = (Snode*)malloc(sizeof(Snode));
	new->data = data;
	new->link = LS->top;
	LS->top = new;
}
int pop(LinkedStack* LS) {
	Snode* deleted = LS->top;
	int data = deleted->data;
	LS->top = LS->top->link;
	free(deleted);
	return data;
}
int peek(LinkedStack* LS) {
	return LS->top->data;
}
int main() {
	LinkedStack lstack;
	init_stack(&lstack);
	push(&lstack, 10);
	push(&lstack, 20);
	push(&lstack, 30);
	print_stack(&lstack);
	printf("top = %d\n", peek(&lstack)); pop(&lstack);
	printf("top = %d\n", peek(&lstack)); pop(&lstack);
	printf("top = %d\n", peek(&lstack)); pop(&lstack);
	pop(&lstack);
}