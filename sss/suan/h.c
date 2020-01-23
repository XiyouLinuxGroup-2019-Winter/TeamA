#include <stdio.h>
int main()
{
	int i,j,k,l,n,m=0;;
	int a[3];
        scanf("%d",&n);
	int t;
	for(i=1;i<=n;i++)
	{       t=0;   
		for(l=0;l<3;l++)
		{
			scanf("%d",&a[l]);
			if(a[l]==1)
			t++;
                }
		if(t>=2)
		m++;
	}
	printf("%d",m);
}

