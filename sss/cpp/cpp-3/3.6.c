#include <stdio.h>
int main()
{
	int i;
	float j=3.0e-23;
	printf("请输入夸克数");
	scanf("%d",&i);
	float k=i*950.0;

	printf("%e",k/j);
}

