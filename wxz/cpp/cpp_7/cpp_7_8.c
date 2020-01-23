#include <stdio.h>
#define level1 8.75
#define level2 9.33
#define level3 10.00
#define level4 11.20
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
	float money,taxes,hour,money1,realmoney,pay,real_hour;
	money=taxes=hour=money1=realmoney=0;
	int level;

	printf("****************************************************************");
	printf("Enter the number corresponding to the desired pay rate or action");
	printf("1)$8.75/hr      2)$9.33/hr");
	printf("3)$10.00/hr     4)$11.20/hr");
	printf("5)quit");
	printf("****************************************************************");
	while(scanf("%d",&level)==1 && level!=5)
	{
		switch(level)
		{
			case '1':
				pay=level1;
				break;
			case '2':
				pay=level2;
				break;
			case '3':
				pay=level3;
				break;
			case '4':
				pay=level4;
				break;
			default:
				printf("You should enter the number is 1 to 4 (5 to quit)");
				printf("Please enter the right number:\n");
				continue;
		}
		printf("Please input the number of your hours a week:");
		scanf("%f",&hour);
//float money,taxes,hour,money1,realmoney,pay,real_hour
		if(hour<=limit)
			real_hour=hour;
		else
			real_hour=hour+(hour-limit)*time;
		money=real_hour*pay;
		money1=money-dollar_1;
		if(money1<=0)
			taxes+=money*rate_1;
		else
		{
			taxes+=rate_1*dollar_1;
			if(money1<=dollar_2)
				taxes+=money1*rate_2;
				else
				{
					taxes+=dollar_2*rate_2;
					taxes+=(money1-dollar_2)*rate_3;
				}

		}
		realmoney=money-taxes;
		printf("%f %f %f",money,taxes,realmoney);

	}
}
