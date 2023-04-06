#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h> // sqrt() 함수 사용을 위한 헤더 파일
#include<malloc.h>// 일부 데이터의 힙 이동
#define STUDENT 1000 // 배열의 크기 1000으로 초기화

//구조체 타입 student로 학생들 정의
typedef struct student {
    char name[100];
    int student_number;
    int score;
}student;


float get_mean(int cnt, student students[]); //get_mean() 함수가 있다는 것을 도입부에서부터 알려주어야 함
float get_deviation(int cnt, student students[], float average); //get_deviation() 함수가 있다는 것을 도입부에서부터 알려주어야 함

int main(void)
{
    struct student students[STUDENT];// 배열 요소 값의 초기화

    int cnt; //학생 수
    float average = 0; // 평균
    float standard = 0; // 표준편차

    printf("학생 수 입력: ");
    scanf("%d", &cnt);

    printf("학생 정보 입력\n");

    for (int i = 1; i <= cnt; i++)
    {
        printf("이름 : "); //학생 성명 입력
        scanf("%s", students[i].name);
        printf("학번 : "); //학번 입력
        scanf("%d", &students[i].student_number);
        printf("성적 : "); //점수 입력
        scanf("%d", &students[i].score);
        printf("\n");
    }

    for (int i = 1; i <= cnt; i++)
    {
        average = get_mean(cnt, students); //get_mean() 함수 호출
    }
    for (int i = 1; i <= cnt; i++)
    {
        standard = get_deviation(cnt, students, average); //get_devition() 함수 호출
    }
    average = average / cnt;
    standard = standard / cnt;
    standard = sqrt(standard);

    printf("평균 : %.2f\n", average); //평균 출력
    printf("표준편차: %.2f\n", standard);
}

float get_mean(int cnt, student students[]) //get_mean() 함수 선언
{
    float sum = 0;

    for (int i = 1; i <= cnt; i++)
    {
        sum += students[i].score;
    }
    return sum;
}

float get_deviation(int cnt, student students[], float average) //get_devition() 함수 선언
{
    float super = 0;

    for (int i = 1; i <= cnt; i++)
        super = super + ((students[i].score - average) * (students[i].score - average));

    return super;
}