#include<stdio.h>
#include<math.h>
int main(void)
{
float value_1, value_2;
printf("Please enter two decimals.(q to quit)\n");
while (2 == scanf("%f %f", &value_1, &value_2))
{
printf("result = %.3f\n",
fabs(value_1 - value_2) / (value_1 * value_2));
printf("\nPlease enter two decimals.(q to quit)\n");
}
printf("bye\n");
return 0;
}
