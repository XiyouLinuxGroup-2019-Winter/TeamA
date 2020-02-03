#include<stdio.h>
int main(void)
{
int upper, lower;
int i;
int s_squares = 0;
int enter;
printf("Enter lower and upper integer limits(lower >= upper to quit): ");
enter = scanf("%d %d", &lower, &upper);
while ((upper > lower) && (enter == 2))
{
for (i = lower; i <= upper; i++)
s_squares += i * i;
printf("The sums of the squares from %d to %d is %d\n",
lower * lower, upper * upper, s_squares);
printf("Enter next set of limits: ");
enter = scanf("%d %d", &lower, &upper);
}
printf("Done!\n");
return 0;
}
 
