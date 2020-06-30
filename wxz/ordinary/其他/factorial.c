#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	long long int s=0;
	for(i=0;i<n;i++)
	{
		int a=1;
		for(j=0;j<i;j++)
		{
			a=a*j;
		}
		s+=a;
	}
	printf("%lld\n",s);
}
