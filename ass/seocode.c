#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h> // sqrt() �Լ� ����� ���� ��� ����
#include<malloc.h>// �Ϻ� �������� �� �̵�
#define STUDENT 1000 // �迭�� ũ�� 1000���� �ʱ�ȭ

//����ü Ÿ�� student�� �л��� ����
typedef struct student {
    char name[100];
    int student_number;
    int score;
}student;


float get_mean(int cnt, student students[]); //get_mean() �Լ��� �ִٴ� ���� ���Ժο������� �˷��־�� ��
float get_deviation(int cnt, student students[], float average); //get_deviation() �Լ��� �ִٴ� ���� ���Ժο������� �˷��־�� ��

int main(void)
{
    struct student students[STUDENT];// �迭 ��� ���� �ʱ�ȭ

    int cnt; //�л� ��
    float average = 0; // ���
    float standard = 0; // ǥ������

    printf("�л� �� �Է�: ");
    scanf("%d", &cnt);

    printf("�л� ���� �Է�\n");

    for (int i = 1; i <= cnt; i++)
    {
        printf("�̸� : "); //�л� ���� �Է�
        scanf("%s", students[i].name);
        printf("�й� : "); //�й� �Է�
        scanf("%d", &students[i].student_number);
        printf("���� : "); //���� �Է�
        scanf("%d", &students[i].score);
        printf("\n");
    }

    for (int i = 1; i <= cnt; i++)
    {
        average = get_mean(cnt, students); //get_mean() �Լ� ȣ��
    }
    for (int i = 1; i <= cnt; i++)
    {
        standard = get_deviation(cnt, students, average); //get_devition() �Լ� ȣ��
    }
    average = average / cnt;
    standard = standard / cnt;
    standard = sqrt(standard);

    printf("��� : %.2f\n", average); //��� ���
    printf("ǥ������: %.2f\n", standard);
}

float get_mean(int cnt, student students[]) //get_mean() �Լ� ����
{
    float sum = 0;

    for (int i = 1; i <= cnt; i++)
    {
        sum += students[i].score;
    }
    return sum;
}

float get_deviation(int cnt, student students[], float average) //get_devition() �Լ� ����
{
    float super = 0;

    for (int i = 1; i <= cnt; i++)
        super = super + ((students[i].score - average) * (students[i].score - average));

    return super;
}