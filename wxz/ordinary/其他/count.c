#include <stdio.h>
int main()
{
	int n,x;
	int i;
	int a,b,c;
	int count=0;
	scanf("%d %d",&n,&x);
	for(i=1;i<=n;i++)
	{
		a=i;
		b=a%10;
		c=a/10;
		if(b==c)
		count++;
	}
	pritnf("%d",count);
}
