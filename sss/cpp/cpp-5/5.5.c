#include <stdio.h>
int main()
{
	int i,n,k=0;
	printf("请输入一个数");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
            k+=i;
	printf("%d",k);
}


