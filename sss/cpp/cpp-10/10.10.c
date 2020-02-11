#include <stdio.h>
void copy(double*,double*,double*,int );
int main()
{
	double a[4];
	double b[4];
	double c[4];
	for(int i=0;i<4;i++)
		scanf("%lf",&a[i]);
	for(int j=0;j<4;j++)
		scanf("%lf",&b[j]);
	copy(a,b,c,4);
	for(int i=0;i<4;i++)
	printf("%lf",c[i]);
}
void copy(double*a,double*b,double*c,int n)
{
	for(int i=0;i<n;i++)
		*(c+i)=*(a+i)+*(b+i);
}


