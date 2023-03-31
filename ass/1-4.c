#include <stdio.h>
//질문하기

int search(int arr[], int N, int place) {

    int i;
    int place = 0;

    for (i = 0; i < 10; i++)
    {
        if (N == arr[i])
        {
            place++;
        }
    }
}
int main() {

    int arr[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };
    int N;
    int place;

    scanf("%d", &N);

    search(arr, N, place);

    return 0;
}
