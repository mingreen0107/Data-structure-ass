#include <stdio.h>

typedef struct Movie {
	char title[50];
	int release;
	int viewers;
} Movie;

int main() {

	Movie m1 = { "��", 2014, 0 };
	Movie m2 = m1;
	if (!strcmp(m1.title, m2.title) && m1.release == m2.release && m1.viewers == m2.viewers) printf("���� ��ȭ");
}


/*int main() {

	int i = 100;
	int* p2i = &i;

	p2i = &i;
	*i = NULL;
	p2i = &i + 1;
	p2i = 1000;
	*p2i = 10;
	p2i = &(i + 1);
	*p2i = i + 1;
	p2i++;

	return 0;
}*/