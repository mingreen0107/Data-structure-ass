/* 135page 17
학생들이 둥글게 둘러 앉아 숫자 하나(n)을 결정한다.
각자 자신의 이름을 적은 종이를 모자에 집어넣고 대표가 그 중 한 장의 종이를 뽑는다.
이름이 뽑힌 사람으로부터 시작해서  시계 방향으로 숫자 n번째 사람이 원에서 제거되고
다음 사람부터 반대 방향으로 다시 n번째 사람이 원에서 제거된다.
최종적으로 남은 사람은 누구인가?
위 내용을 처리하는 프로그램을 아래 사항을 참고하여 작성하시오
(1) 학생들의 이름을 차례대로 입력받아 연결리스트로 구성
(2) n을 사용자로부터 입력받음
(3) 매번 학생이 줄어들 때마다 제거된 사람의 이름과 남은 사람들을 출력
(4) 최종 남은 학생을 출력 */
#include <stdio.h>
#include <stdlib.h>

typedef struct List {   // 구조체 List 정의
    struct List* link;   // List*형 변수 link
    char* name;         // char*형 변수 name
}List;               // struct List == List

/* head의 바로 뒤에 연결리스트 추가 */
void Add_Linked_List(List* head, char* name) {
    List* add = (List*)malloc(sizeof(List));   // 동적 메모리 공간 할당
    add->link = head->link;   // head->link가 가리키는 곳을 add>link가 가리킴
    head->link = &add->link;   // head->link는 add-link를 가리킴
    add->name = name;   // add-name에 입력받은 이름 저장
}

int main(void) {
    List* head;   // List*형 변수 head 선언
    head = (List*)malloc(sizeof(List));   // 동적으로 sizeof(List)의 크기 만큼 메모리 공간을 할당 받음
    head->link = NULL;   // head->link는 아무곳도 가리키지 않음
    char end = 1;
    while (end != '0') {
        printf("이름 입력(0을 입력하면 종료 : ");   // 출력
        char name[10];   // 이름을 입력 받기 위해 선언
        scanf("%s", name);   // 입력 받은 이름을 저장
        Add_Linked_List(head, name);   // 함수를 불러와 연결리스트 추가
        end = name[0];   // 0을 입력받으면 종료
    }

    int N;
    printf("숫자 하나(N) 입력: ");
    scanf("%d", &N);
    return 0;
}