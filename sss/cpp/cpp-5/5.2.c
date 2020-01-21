#include <stdio.h>
int main()
{
	int i;
	printf("请输入一个数");
	scanf("%d",&i);
	int n=i+10;
	for(;i<=n;i++)
		printf("%d ",i);
}

