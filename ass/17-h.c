/* 135page 17
�л����� �ձ۰� �ѷ� �ɾ� ���� �ϳ�(n)�� �����Ѵ�.
���� �ڽ��� �̸��� ���� ���̸� ���ڿ� ����ְ� ��ǥ�� �� �� �� ���� ���̸� �̴´�.
�̸��� ���� ������κ��� �����ؼ�  �ð� �������� ���� n��° ����� ������ ���ŵǰ�
���� ������� �ݴ� �������� �ٽ� n��° ����� ������ ���ŵȴ�.
���������� ���� ����� �����ΰ�?
�� ������ ó���ϴ� ���α׷��� �Ʒ� ������ �����Ͽ� �ۼ��Ͻÿ�
(1) �л����� �̸��� ���ʴ�� �Է¹޾� ���Ḯ��Ʈ�� ����
(2) n�� ����ڷκ��� �Է¹���
(3) �Ź� �л��� �پ�� ������ ���ŵ� ����� �̸��� ���� ������� ���
(4) ���� ���� �л��� ��� */
#include <stdio.h>
#include <stdlib.h>

typedef struct List {   // ����ü List ����
    struct List* link;   // List*�� ���� link
    char* name;         // char*�� ���� name
}List;               // struct List == List

/* head�� �ٷ� �ڿ� ���Ḯ��Ʈ �߰� */
void Add_Linked_List(List* head, char* name) {
    List* add = (List*)malloc(sizeof(List));   // ���� �޸� ���� �Ҵ�
    add->link = head->link;   // head->link�� ����Ű�� ���� add>link�� ����Ŵ
    head->link = &add->link;   // head->link�� add-link�� ����Ŵ
    add->name = name;   // add-name�� �Է¹��� �̸� ����
}

int main(void) {
    List* head;   // List*�� ���� head ����
    head = (List*)malloc(sizeof(List));   // �������� sizeof(List)�� ũ�� ��ŭ �޸� ������ �Ҵ� ����
    head->link = NULL;   // head->link�� �ƹ����� ����Ű�� ����
    char end = 1;
    while (end != '0') {
        printf("�̸� �Է�(0�� �Է��ϸ� ���� : ");   // ���
        char name[10];   // �̸��� �Է� �ޱ� ���� ����
        scanf("%s", name);   // �Է� ���� �̸��� ����
        Add_Linked_List(head, name);   // �Լ��� �ҷ��� ���Ḯ��Ʈ �߰�
        end = name[0];   // 0�� �Է¹����� ����
    }

    int N;
    printf("���� �ϳ�(N) �Է�: ");
    scanf("%d", &N);
    return 0;
}