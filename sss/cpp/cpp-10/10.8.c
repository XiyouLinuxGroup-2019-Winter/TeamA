#include <stdio.h>
void asd(double *,double *,int n);
int main()
{
	double a[7]={1.1,2.2,3.3,4.4,5.5,6.6,7.7};
	double b[3];
	asd(&a[2],&b[0],3);
	for(int i=0;i<3;i++)
		printf("%lf",b[i]);
}
void asd(double *A,double *B,int n)
{
	for(int i=0;i<n;i++)
		B[i]=A[i];
}

