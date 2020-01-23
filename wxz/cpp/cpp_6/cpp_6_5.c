#include <stdio.h>
int main()
{
	int upperlimit,lowerlimit;
	int i;
	scanf("%d %d",&upperlimit,&lowerlimit);
	for(i=lowerlimit;i<=upperlimit;i++)
	printf("%10d%10d%10d\n",i,i*i,i*i*i);
}
