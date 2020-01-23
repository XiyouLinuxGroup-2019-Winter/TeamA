#include <stdio.h>
#define salary 10.00
#define time 1.5
#define rate_1 0.15
#define rate_2 0.2
#define rate_3 0.25
#define dollar_1 300
#define dollar_2 150
#define limit 40
int main()
{
	float money,taxes,hour,money1,realmoney;
	money=taxes=hour=money1=

	realmoney;
	float n;
	scanf("%f",&n);
	if(n>limit)
	hour=limit+(n-limit)*time;
				
	money=hour*salary;
	
	if(money<=dollar_1)
	taxes=money*rate_1;
	else if(money<=dollar_2)
	taxes=rate_1*dollar_1+(money-dollar_1)*rate_2;
	else
	taxes=dollar_1*rate_1+dollar_2*rate_2+(money-dollar_1-dollar_2)*rate_3;
	realmoney=money-taxes;
	printf("%f %f %f\n",money,taxes,realmoney);
}
