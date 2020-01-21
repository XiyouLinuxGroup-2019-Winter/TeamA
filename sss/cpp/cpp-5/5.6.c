#include <stdio.h>
int main()
{
	int i,j,n;
	j=0;
	printf("请输入一个数");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		j+=i*i;
         printf("%d",j);
}

