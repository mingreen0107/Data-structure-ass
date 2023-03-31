#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void search(int arr[], int N, int* place) {

    int i;

    for (i = 0; i < 10; i++)
    {
        if (N == arr[i])
        {
            //i의 값을 place에 저장
           *place = i;

           //값이 나오면 바로 끝내기 위해
           return;
        }
    }
}ㅣ
int main() {

    int arr[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };
    int N;
    int place;

    scanf("%d", &N);

    //place가 void형으로 반환될 때 주소로 반한되어 주소값을 줘야한다
    search(arr, N, &place);

    printf("arr[%d]의 위치에 있다", place);

    return 0;
}
