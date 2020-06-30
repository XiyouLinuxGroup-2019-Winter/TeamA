#include <stdio.h>
int main()
{
	int n,i,x,a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			int sum=0;
		while(x--)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
		}
}
