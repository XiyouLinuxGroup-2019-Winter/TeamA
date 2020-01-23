#include <stdio.h>
#include <math.h>
int main()
{
	int a[8];
	int i;
	for(i=0;i<8;i++)
	a[i]=pow(2,i);
	i=0;
	do
	printf("%d\t",a[i]);
	while(++i<8);
	
}
