#include<stdio.h>
#define BASE_PAY 10
#define BASE_TIME 40
#define OVER_PAY 15
#define TAX_1 300
#define TAX_2 150
#define TAX_1_RATE 0.15f
#define TAX_2_RATE 0.2f
#define TAX_OT_RATE 0.25f
int main(void)
{
unsigned int time;
float wage,tax;
printf("Please enter the number of hours you work a week.\n");
scanf("%u", &time);
if (time <= BASE_TIME)
wage = time * (float)BASE_PAY;
else
wage = BASE_TIME * (float)BASE_PAY + (time - BASE_TIME) * OVER_PAY;
if (wage < TAX_1)
tax = wage * TAX_1_RATE;
else if (wage < TAX_2)
tax = TAX_1 * TAX_1_RATE + (wage - TAX_1) * TAX_2_RATE;
else
tax = TAX_1 * TAX_1_RATE + TAX_2 * TAX_2_RATE + (wage - TAX_2) * TAX_OT_RATE;
printf("Total wage: %.2f\n", wage);
printf("Tax: %.2f\n", tax);
printf("Net income: %.2f\n", wage - tax);
return 0;
}
 
