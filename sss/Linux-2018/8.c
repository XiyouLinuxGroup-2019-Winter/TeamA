#include <stdio.h>
int f(unsigned int num);
int  main()
{
	int num;
	scanf("%d",&num);
	int h=f(num);
	printf("%d",h);
}
int f(unsigned int num)
{
	int i;
	for(i=0;num;i++)
		num&(num-1);
	return i;
}

