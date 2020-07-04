#include <stdio.h>
void sum(const int *a,const int *b,int *c,int n)
{
	for(int i=0;i<n;i++)
		c[i]=a[i]+b[i];
}
int main()
{
	int a[4]={2,4,5,8};
	int b[4]={1,0,4,6};
	int c[4];
	sum(a,b,c,4);
	for(int i=0;i<4;i++)
		printf("%d ",c[i]);
	printf("\n");
}
