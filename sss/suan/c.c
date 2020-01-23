#include <stdio.h>
int main()
{
	int i,l,n,sum;
	while(scanf("%d",&n)==1)
	{          sum=0;
		for(i=1;i<=n;i++)
		{  
	           l=0;	
                   scanf("%d",&l);
                   sum+=l;
		}
		printf("%d\n",sum);
	}
}

