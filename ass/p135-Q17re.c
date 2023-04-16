#include <stdio.h>
#include <stdlib.h> //malloc�Լ��� ����ϱ� ���� ��� ����
#include <string.h>
#include <time.h>

typedef struct Node { // �̸��� �����ִ� ��� ����
    char name[10];
    struct Node* data;
    struct Node* next;
} Node;

Data LRemove(List* plist)
{
    Node* rnode = plist->cur;
    Data rdata = rnode->data;

    plist->cur = plist->cur->prev; // �ι�° ��带 ������ ��� cur�� ù��° ��带 ����Ų��.

    if (rnode == plist->head)
    {
        if (rnode->next == NULL)
            plist->head = NULL; // ��尡 �ϳ��� ��� head�� ����.
        else
        {
            plist->head = rnode->next; // ù��° ����� ��� head�� ��ü�Ѵ�.
            plist->head->prev = NULL;
        }
    }
    else
    {
        if (rnode->next == NULL)
            rnode->prev->next = NULL; // ������ ����� ��� ���� ����� next�� ����.
        else
        {
            rnode->prev->next = rnode->next; // �߰��� ����� ��� �յ� ��带 ���� �����Ѵ�.
            rnode->next->prev = rnode->prev;
        }
    }

    free(rnode);
    plist->numOfData--;
    return rdata;
}
int main() {
    if (LFirst(&list, &data))
    {
        while (list.cur->next != NULL) // �ֱٿ� ã�� ����� next�� �����ϴ��� �˻��Ѵ�.
        {
            if (LNext(&list, &data)) // ���� ��带 ã�Ƽ� �����Ѵ�.
                LRemove(&list); // ù ����� �ι�° ������ ó���ϰ� �ȴ�.           
        }

        LFirst(&list, &data); // ������ ������ �˻��� ��ġ�� head�� �˻��Ͽ� ó���Ѵ�.
        LRemove(&list);
    }
}