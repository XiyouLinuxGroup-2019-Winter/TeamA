#include <stdio.h>
#define type_1 17850
#define type_2 23900
#define type_3 29750
#define type_4 14875
#define rate_1 0.15
#define rate_2 0.28
void menu()
{
	printf("1)单身      　　　　　　　2)户主\n");
　　　　printf("3)已婚，共有　            4)已婚，离异  \n");
}
int main()
{
	char ch;
	int taxes;
	double money=0;
	menu();
	scanf("%c %d",&ch,&taxes);
	while(ch!='#')
	{
		switch(ch)
		{
			case '1':
			if(taxes<=type_1)
			money=taxes*rate_1;
			else
			money=type_1*rate_1+(taxes-type_1)*rate_2;
			break;
			case '2':
			if(taxes<=type_2)
			money=taxes*rate_1;
			else
			money=type_2*rate_1+(taxes-type_2)*rate_2;
	`		break;
			case '3':
                        if(taxes<=type_3)
                        money=taxes*rate_1;
                        else
                        money=type_3*rate_1+(taxes-type_3)*rate_2;
			break;
			case '4':
                        if(taxes<=type_4)
                        money=taxes*rate_1;
                        else
                        money=type_4*rate_1+(taxes-type_4)*rate_2;
                        break;
			default:
			break;
		}
		printf("%f\n",money);
		scanf("%c %d",&ch,&taxes);
	}
}
