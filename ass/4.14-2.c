#include <stdio.h>
#include <stdlib.h>

typedef struct NODE //����ü ����
{
    struct NODE* llink;
    int data;
    struct NODE* rlink;
} NODE;
NODE* head;
NODE* tail;

//��� ���� �Լ�
NODE* makenode(int value) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->llink = NULL;
    node->data = value;
    node->rlink = NULL;
    return node;
}

//��� �Լ�
void print() {
    NODE* p;
    p = head;
    while (p->rlink != tail) {
        printf("%d-->", p->data);
        p = p->rlink;
    }
    printf("%d", p->data);
}

//�ʱ�ȭ �Լ�
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

//�ڷκ��� ��� �߰��ϴ� �Լ�
void push_back(int value) {
    NODE* newnode = makenode(value);
    NODE* p;
    p = tail;
    p->llink->rlink = newnode;
    newnode->llink = p->llink;
    p->llink = newnode;
    newnode->rlink = p;
}

//main�Լ�
int main() {
    init(); //head�� tail �ʱ�ȭ (data = 0)
    push_back(10); //10 �߰�
    push_back(30); //30 �߰�
    push_back(50); //50 �߰�
    print();  //���
    return 0;
}