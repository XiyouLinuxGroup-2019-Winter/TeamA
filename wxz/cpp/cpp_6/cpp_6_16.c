#include <stdio.h>
int main()
{
	int count=0;
	const double money=100;
	double account=money;
	double remain;
	while(account>0)
	{
		account+=account*0.08;
		remain=account-10;
		account=remain;
		count++;
	}
	printf("%d\n",count);
	
}
