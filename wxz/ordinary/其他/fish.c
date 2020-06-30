#include <stdio.h>
int main()
{
	int x,n,i,j;
	int sum=0;
	scanf("%d %d",&x,&n);
	for(i=1;i<=n;i++)
	{
		if(x!=6&&x!=7)
		sum+=250;
		else if(x==7)
		x=0;
		x++;
	}
	printf("%d\n",sum);
}
