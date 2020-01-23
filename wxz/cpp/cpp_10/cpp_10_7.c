#include <stdio.h>
void copy_ptr(double *source,double *target,int n)
{
	for(int i=0;i<n;i++)
	target[i]=source[i];
}
int main()
{
	double source[7]={1.1,2.2,3.3,4.4,5.5,6.6,7.7};
	double target[3];
	copy_ptr(&source[2],target,3);
	for(int i=0;i<3;i++)
		printf("%lf\n",target[i]);
}
