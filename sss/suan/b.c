#include <stdio.h>
int main()
{
	int m,i,j,k,l,n;
	scanf("%d",&n);
        int sum;
	for(i=1;i<=n;i++)
	{    sum=0;
	    scanf("%d",&l);
	    for(k=1;k<=l;k++)
	    {        m=0;
		    scanf("%d",&m);
                    sum+=m;
	    }
	   
	    printf("%d\n",sum);
	}
}



