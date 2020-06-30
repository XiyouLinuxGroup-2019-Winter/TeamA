#include <stdio.h>
int main()
{
	int n,i,x;
	int sum=0;
	while(scanf("&d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
		scanf("%d",&x);
		sum+=x;
		}
		printf("%d\n",sum);
		sum=0;
	}
} 
