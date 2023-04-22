// �̾��ִ� �������� ������ �� ��
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE* llink;
    int data;
    struct NODE* rlink;
} NODE;
struct NODE* tail;

//��� ���� �Լ�
NODE* makenode(int value) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->llink = NULL;
    node->data = value;
    node->rlink = NULL;
    return node;
}

//��� �Լ�
void print(NODE* p) {
    while (p->llink != NULL) {
        printf("%d-->", p->data);
        p = p->rlink;
    }
    printf("%d", p->data);
}

//�ʱ�ȭ �Լ�
void init() {
    tail = (NODE*)malloc(sizeof(NODE));
    tail->data = 0;
    tail->llink = tail;
    tail->rlink = tail;
}

//�ڷκ��� ��� �߰��ϴ� �Լ�
NODE* push_back(int value, NODE* p) {
    NODE* newnode = makenode(value);
    if (p->rlink == NULL) { // p == tail �� ��
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

//main�Լ�
int main() {
    init();
    NODE* p = tail;
    push_back(10, p);
    push_back(30, p);
    push_back(50, p);
    print(p);  //���
    return 0;
}