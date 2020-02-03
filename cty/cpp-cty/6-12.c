#include <stdio.h>
#include <math.h>

int main(void)
{
float number;
float sum_1, sum_2;
float deno;
_Bool enter_is_right;
printf("Please enter the total number of time(<=0 to quit): ");
enter_is_right=scanf("%f", &number);
while ((number > 0) && enter_is_right)
{
for (deno = 1.0, sum_1 = 0, sum_2 = 0; deno <= number; deno++)
{
sum_1 += 1.0f / deno;
sum_2 += (1.0f / deno) * (float)pow(-1.0, deno + 1);
}
printf("sum_1= %f\nsum_2= %f\n", sum_1, sum_2);
printf("\nPlease enter the total number of time(<=0 to quit): ");
scanf("%f", &number);
}
printf("bye\n");
return 0;
}
 
