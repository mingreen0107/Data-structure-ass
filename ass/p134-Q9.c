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
    NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
    node->llink = NULL;
    node->data = value;
    node->rlink = NULL;
    return node;
}

//��� �Լ�
void print(NODE* p) {
    while (p->llink != NULL) {
        printf("%d-->", p->data);
        p = p->llink;
    }
    printf("%d", p->data);
}

//�ʱ�ȭ �Լ�
void init() {
    tail = (struct NODE*)malloc(sizeof(struct NODE));
    tail->data = 0;
    tail->llink = tail;
    tail->rlink = NULL;
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
    return newnode;
}

//main�Լ�
int main() {
    init();
    NODE* p = tail;
    p = push_back(10, p);
    p = push_back(30, p);
    p = push_back(50, p);
    print(p);  //���
    return 0;
}