#include <stdio.h>
#include <stdlib.h>

typedef struct NODE //구조체 선언
{
    struct NODE* llink;
    int data;
    struct NODE* rlink;
} NODE;
NODE* head;
NODE* tail;

//노드 생성 함수
NODE* makenode(int value) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->llink = NULL;
    node->data = value;
    node->rlink = NULL;
    return node;
}

//출력 함수
void print() {
    NODE* p;
    p = head;
    while (p->rlink != tail) {
        printf("%d-->", p->data);
        p = p->rlink;
    }
    printf("%d", p->data);
}

//초기화 함수
void init() {
    head = (NODE*)malloc(sizeof(NODE));
    tail = (NODE*)malloc(sizeof(NODE));
    head->data = 0;
    tail->data = 0;

    head->rlink = tail;
    head->llink = head;
    tail->rlink = tail;
    tail->llink = head;
}

//뒤로부터 노드 추가하는 함수
void push_back(int value) {
    NODE* newnode = makenode(value);
    NODE* p;
    p = tail;
    p->llink->rlink = newnode;
    newnode->llink = p->llink;
    p->llink = newnode;
    newnode->rlink = p;
}

//main함수
int main() {
    init(); //head와 tail 초기화 (data = 0)
    push_back(10); //10 추가
    push_back(30); //30 추가
    push_back(50); //50 추가
    print();  //출력
    return 0;
}