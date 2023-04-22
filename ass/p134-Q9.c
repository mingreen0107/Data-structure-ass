// 이어주는 과정에서 오류가 난 듯
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE* llink;
    int data;
    struct NODE* rlink;
} NODE;
struct NODE* tail;

//노드 생성 함수
NODE* makenode(int value) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->llink = NULL;
    node->data = value;
    node->rlink = NULL;
    return node;
}

//출력 함수
void print(NODE* p) {
    while (p->llink != NULL) {
        printf("%d-->", p->data);
        p = p->rlink;
    }
    printf("%d", p->data);
}

//초기화 함수
void init() {
    tail = (NODE*)malloc(sizeof(NODE));
    tail->data = 0;
    tail->llink = tail;
    tail->rlink = tail;
}

//뒤로부터 노드 추가하는 함수
NODE* push_back(int value, NODE* p) {
    NODE* newnode = makenode(value);
    if (p->rlink == NULL) { // p == tail 일 때
        newnode->llink = p;
        newnode->rlink = p;
        p->llink = newnode;
        p->rlink = newnode;
    }
    else {
        newnode->rlink = p;
        p->llink = newnode;
    }
    return p;
}

//main함수
int main() {
    init();
    NODE* p = tail;
    push_back(10, p);
    push_back(30, p);
    push_back(50, p);
    print(p);  //출력
    return 0;
}