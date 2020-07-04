#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int flag;
	for(i=2;i<=n;i++)
	{
		flag=0;
		for(j=2;(j*j)<=i;j++)
		{
			if(i%j==0)
			flag=1;
		}
		if(flag==0)
		printf("%d ",i);
	}
}
