#include<stdio.h>
#include<math.h>
float result(float v1, float v2);
int main(void)
{
float value_1, value_2;
printf("Please enter two decimals.(q to quit)\n");
while (2 == scanf("%f %f", &value_1, &value_2))
{
printf("result = %.3f\n",result(value_1,value_2));
printf("\nPlease enter two decimals.(q to quit)\n");
}
printf("bye\n");
return 0;
}
float result(float v1, float v2)
{
float result;
result = (float)fabs(v1 - v2) / (v1 * v2);
return result;
}
 
