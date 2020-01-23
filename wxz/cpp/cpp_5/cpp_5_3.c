#include <stdio.h>
#define T 7
int main()
{
	int n;
	int day,week;
	scanf("%d",&n);
	while(n>0)
	{
		day=n%T;
		week=n/T;
		printf("%d days are %d weeks, %d days.",n,week,day);
		break;
	}
}
