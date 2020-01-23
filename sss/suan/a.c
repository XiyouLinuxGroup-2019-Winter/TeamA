#include <stdio.h>
int main()
{
	int i,j,k,n;
	while(scanf("%d",&n)==1&&n!=0)
	{       k=0;
		for(i=1;i<=n;i++)
		{
                        j=0;
			scanf("%d",&j);
			k+=j;
		}
		printf("%d\n",k);
	}
}

