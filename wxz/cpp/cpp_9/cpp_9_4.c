#include <stdio.h>
double harmonic(double a,double b);
int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	double c=harmonic(a,b);
	printf("%lf",c);
}
double harmonic(double a,double b)
{
	double c,d;
	c=1/a;
	d=1/b;
	double e;
	e=(c+d)/2;
	double f;
	f=1/e;
	return f;
}
