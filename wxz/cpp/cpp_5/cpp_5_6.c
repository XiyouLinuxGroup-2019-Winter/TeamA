#include <stdio.h>
int main()
{
	int count,sum;
	count=0;
	sum=0;
	int n;
	scanf("%d",&n);
	while(count++<n)
	sum+=count*count;
	printf("sum=%d\n",sum);
}
