#include<stdio.h>
#define BASE_TIME 40
#define OVER_PAY 15
#define TAX_1 300
#define TAX_2 150
#define TAX_1_RATE 0.15f
#define TAX_2_RATE 0.2f
#define TAX_OT_RATE 0.25f
float level(void);
void star(void);
int main(void)
{
    unsigned int time;
    float wage, tax, salary;
 
    while(1)
    {
        if ((salary = level()) == 0)
            break;
        printf("Please enter the number of hours you work a week.\n");
        scanf("%u", &time);
        if (time <= BASE_TIME)
            wage = time * (float)salary;
        else
            wage = BASE_TIME * (float)salary + (time - BASE_TIME) * OVER_PAY;
        if (wage < TAX_1)
            tax = wage * TAX_1_RATE;
        else if (wage < TAX_2)
            tax = TAX_1 * TAX_1_RATE + (wage - TAX_1) * TAX_2_RATE;
        else
            tax = TAX_1 * TAX_1_RATE + TAX_2 * TAX_2_RATE + (wage - TAX_2) * TAX_OT_RATE;
        printf("Total wage: %.2f\n", wage);
        printf("Tax: %.2f\n", tax);
        printf("Net income: %.2f\n", wage - tax);
    }
 
    return 0;
}
 
float level(void)
{
    const float level_1 = 8.75f;
    const float level_2 = 9.33f;
    const float level_3 = 10.00f;
    const float level_4 = 11.20f;
    float salary;
    int flag;
    _Bool cycle;
 
    do
    {
        cycle=0;
        star();
        printf("\nEnter the number corresponding to the desired pay rate or action.\n\n");
        printf("1) $8.75/hr\t\t2) $9.33/hr\n\n");
        printf("3) $10.00/hr\t\t4) $11.20/hr\n\n");
        printf("5) quit\n\n");
        star();
        printf("Your choice: ");
        scanf("%d", &flag);
        switch (flag)
        {
        case 1: salary = level_1; break;
        case 2: salary = level_2; break;
        case 3: salary = level_3; break;
        case 4: salary = level_4; break;
        case 5: salary = 0; printf("bye\n"); break;
        default: 
            printf("Please enter right number.\n"); 
            cycle = 1;
            break;
        }
    }while(cycle==1);
 
    return salary;
}
 
void star(void)
{
    printf("********************************************************************\n");
}
