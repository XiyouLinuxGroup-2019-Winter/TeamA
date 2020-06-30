#include <stdio.h>
int main()
{
	int n,a;
	while(1)
	{
		int s=0;
		scanf("%d",&a);
		if(a==0)
		break;
		while(a--)
		{
			scanf("%d",&n);
			s+=n;
		}
		printf("%d\n",s);
	}
}
