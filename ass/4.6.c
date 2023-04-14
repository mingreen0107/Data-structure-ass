#include<stdio.h>
#include<string.h>

typedef struct List {
    char strData[11];
    struct List* nextList;
} List;

List* searchNode(struct List* list, char* x) {

    List* temp = list;

    while (temp != NULL)
    {
        if (!strcmp(temp->strData, x)) {
            return temp;
        }
        temp = temp->nextList;
    }
    return temp;
}
void main() {
    
    List appleList = { "apple",NULL };
    List BananaList = { "Banana", &appleList };
    List melonList = { "Melon", &BananaList };
    List piList = { "Rassbary", &melonList };
    List nameList = { "신홍기", &piList };
    List* search;

    char strTemp[11];

    printf_s("검색할 것을 입력하세요 : ");
    scanf("%s", strTemp);

    search = searchNode(&nameList, strTemp);

    if (search != NULL)
    {
        printf_s("%s를 리스트에서 찾았습니다.\n", strTemp);
    }
    else {
        printf_s("%s를 리스트에서 찾지 못했습니다.\n", strTemp);
    }
    return;
}

/*#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

Node* search_node(Node* from, DataType data) {
	Node* ptr = from;
	while (ptr) {
		if (ptr->data == data)
			break;
		ptr = ptr->link;
	}
	return ptr;
}

int main() {
	Node* head, * temp;
	int a;

	head = (Node*)malloc(sizeof(Node));
	if (!head) exit(1);
	head->data = 10;
	head->link = NULL;

	temp = (Node*)malloc(sizeof(Node));
	if (!temp) exit(1);
	temp->data = 10;
	temp->link = NULL;
	head->link = temp;

	a = search_node(&head, 10);

	printf("%d ", a);

	free(temp);
	free(head);
}*/