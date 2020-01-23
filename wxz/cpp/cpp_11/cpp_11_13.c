#include <stdio.h>
double my_power(double a,int b);
int main()
{
	double a;
	int b;
	double c=my_power(a,b);
	printf("%lf\n",c);

}
double my_power(double a,int b)
{
	double c;
	if(b<0)
		c=1/my_power(a,-b);
		else if(b>0)
		{
			c=1;
			for(int i=1;i<=b;i++)
			c*=a;
		}
		else if(b==0)
			c=1;
		else if(a==0)
			c=0;
	return c;
}
