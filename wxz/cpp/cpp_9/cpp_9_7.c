#include <stdio.h>
double power(double n,int p)
{
	double result=1;
	if(n==0)
		result=0;
	else if(p==0)
		result=1;
	else
		for(int i=1;i<=p;i++)
			result*=n;
		return result;
}
int main()
{
	double n;
	int p;
	while(scanf("%lf %d",&n,&p)==2)
	{
		double pow=power(n,p);
		printf("%lf\n",pow);
	}
}

