#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void search(int arr[], int N, int* place) {

    int i;

    for (i = 0; i < 10; i++)
    {
        if (N == arr[i])
        {
            //i�� ���� place�� ����
           *place = i;

           //���� ������ �ٷ� ������ ����
           return;
        }
    }
}��
int main() {

    int arr[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };
    int N;
    int place;

    scanf("%d", &N);

    //place�� void������ ��ȯ�� �� �ּҷ� ���ѵǾ� �ּҰ��� ����Ѵ�
    search(arr, N, &place);

    printf("arr[%d]�� ��ġ�� �ִ�", place);

    return 0;
}
