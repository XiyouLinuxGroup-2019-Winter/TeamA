#include <stdio.h>
int main()
{
	int i;
	double n;
	double sum=2;
	double a;
	scanf("%f",&n);
	for(i=1;i<=999999;i++)
	{
		if(sum>n)
		break;
		else
		{
			a=a*0.98;
			sum+=a;
		}
	}
}
