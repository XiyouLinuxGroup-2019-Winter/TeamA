#include <stdio.h>
int main()
{
	float i,j,k;
	printf("请输入兆位每秒");
	scanf("%f",&i);
	printf("请输入兆字节");
	scanf("%f",&j);
	k=j*8/i;
	printf("At %.2f megabits per second,a file of %.2f megabytes downlods in %.2f seconds.",i,j,k);
}

