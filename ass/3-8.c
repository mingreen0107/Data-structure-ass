#include <stdio.h>

char* pa[] = {
	"���� 1",
	"���� 2",
	"���� 3",
	"���� 4",
	"���� 5",
	"���� 6"
};
void error(int err_num)
{
	//error(1)�̱� ������ printf == '���� 2'
	printf(pa[err_num]);
}
main()
{
	error(1);
}