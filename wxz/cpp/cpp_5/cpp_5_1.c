#include <stdio.h>
#define hourtominute 60
int main()
{
	int n,hour,minute;
	scanf("%d",&n);
	while(n>0)
	{
		hour=n/hourtominute;
		minute=n%hourtominute;
		printf("%d %d\n",hour,minute);
		break;
	}
}
