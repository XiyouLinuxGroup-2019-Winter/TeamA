#include <stdio.h>
int main()
{
	int a,m,n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int b=0;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a);
			b=b+a;
		}
		printf("%d\n\n",b);
	}
}
