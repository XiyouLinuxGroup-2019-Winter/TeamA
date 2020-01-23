#include <stdio.h>
double min(double x,double y);
int main()
{
		double x=1.0,y=2.0;
		printf("%f\n",min(x,y));
}
double min(double x,double y)
{
	double value;
	if(x>y)
	value=y;
	else
	value=x;
	return value;
}
