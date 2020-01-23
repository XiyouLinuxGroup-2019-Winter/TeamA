#include <stdio.h>
int main()
{
	double i,sum1,sum2;
	int n,sign=1;
	sum1=0;
	sum2=0;
	scanf("%d",&n);
	for(i=1.0;i<=n;i++)
	{
		sum1+=1.0/i;
		//sign=-sign;
		sum2+=sign*1.0/i;
		sign=-sign;
	}
	printf("%f\n",sum1);
	printf("%f\n",sum2);
}
