#include <stdio.h>
int  call_count();
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int count=call_count();
		printf("%d\n",count);
	}
}
int call_count()
{
	static int count=1;
	return count++;
}
