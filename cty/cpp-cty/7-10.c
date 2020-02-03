#include<stdio.h>
#define TAX_S 17580
#define TAX_H 23900
#define TAX_MC 29750
#define TAX_MD 14875
#define TAX_RATE_B 0.15f
#define TAX_RATE_O 0.28f
void star(void);
int main(void)
{
    unsigned short type;
    unsigned int tax_base;
    float income, tax;
    _Bool flag = 1;
    _Bool re;
 
    do
    {
        do
        {
            re = 0;
            printf("*******************************\n");
            printf("Please choose your tax type.\n");
            printf("1. single\n2. householder\n");
            printf("3. married,common\n4. married,divorced\n");
            printf("5. quit\n\n");
            printf("Your choice: ");
            scanf("%hu", &type);
            switch (type)
            {
            case 1: tax_base = TAX_S; break;
            case 2: tax_base = TAX_H; break;
            case 3: tax_base = TAX_MC; break;
            case 4: tax_base = TAX_MD; break;
            case 5: flag = 0; printf("bye"); break;
            default: 
                printf("\nPlease enter right number.\n"); 
                re = 1;
                break;
            }
        } while (re);
        if (flag)
        {
            printf("Please enter your income: ");
            scanf("%f", &income);
            if (income <= tax_base)
                tax = income * TAX_RATE_B;
            else
                tax = tax_base * TAX_RATE_B + (income - tax_base) * TAX_RATE_O;
            printf("Your tax is %.2f\n\n", tax);
        }
    } while (flag);
    putchar('\n');
 
    return 0;
}
