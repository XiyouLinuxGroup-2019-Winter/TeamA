#include <stdio.h>
void asd(double *,int n);
int main()
{
	int n,i;
	scanf("%d",&n);
	double a[n];
	for( i=0;i<n;i++)
		scanf("%lf",&a[i]);
	asd(a,n);
	for(i=0;i<n;i++)
		printf("%lf",a[i]);
}
void asd(double *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		a[i]=a[n-1-i];
}

