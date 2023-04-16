#include <stdio.h>
#include <stdlib.h> //malloc함수를 사용하기 위한 헤더 파일
#include <string.h>
#include <time.h>

typedef struct Node { // 이름과 관련있는 노드 생성
    char name[10];
    struct Node* data;
    struct Node* next;
} Node;

Data LRemove(List* plist)
{
    Node* rnode = plist->cur;
    Data rdata = rnode->data;

    plist->cur = plist->cur->prev; // 두번째 노드를 삭제할 경우 cur는 첫번째 노드를 가리킨다.

    if (rnode == plist->head)
    {
        if (rnode->next == NULL)
            plist->head = NULL; // 노드가 하나일 경우 head를 비운다.
        else
        {
            plist->head = rnode->next; // 첫번째 노드일 경우 head를 교체한다.
            plist->head->prev = NULL;
        }
    }
    else
    {
        if (rnode->next == NULL)
            rnode->prev->next = NULL; // 마지막 노드일 경우 이전 노드의 next를 비운다.
        else
        {
            rnode->prev->next = rnode->next; // 중간의 노드일 경우 앞뒤 노드를 서로 연결한다.
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
        while (list.cur->next != NULL) // 최근에 찾은 노드의 next가 존재하는지 검사한다.
        {
            if (LNext(&list, &data)) // 다음 노드를 찾아서 삭제한다.
                LRemove(&list); // 첫 실행시 두번째 노드부터 처리하게 된다.           
        }

        LFirst(&list, &data); // 마지막 노드까지 검색을 마치면 head를 검색하여 처리한다.
        LRemove(&list);
    }
}