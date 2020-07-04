#include <stdio.h>
int main()
{
	double a[8],b[8];
	int i,j;
	for(i=0;i<8;i++)
	scanf("%lf",&a[i]);
	for(i=0;i<8;i++)
	printf("%lf ",a[i]);
	printf("\n");
	b[0]=a[0];
	for(i=1;i<8;i++)
	b[i]=a[i]+b[i-1];
	for(i=0;i<8;i++)
	printf("%lf ",b[i]);
	printf("\n");
}
