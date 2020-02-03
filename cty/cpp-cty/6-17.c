#include<stdio.h>
#define ORIGINAL 100
#define RATE 0.08f
int main(void)
{
unsigned int years;
float balance = ORIGINAL;
for (years = 1; balance > 0; years++)
{
balance += balance * RATE;
balance -= 10;
}
printf("years = %d\n", years);
return 0;
}
 
 
