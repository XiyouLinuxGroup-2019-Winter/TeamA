#include <stdio.h>
void larger_of(double *x,double *y);
int main()
{
	double x=4.0,y=5.0;
	larger_of(&x,&y);
	printf("%lf %lf\n",x,y);
}
void larger_of(double *x,double *y)
{
	if(*x<*y)
		*x=*y;
		else
			*y=*x;
}
