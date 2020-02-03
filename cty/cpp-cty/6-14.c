#include<stdio.h>
int main(void)
{
double array_1[8];
double array_2[8];
int i;
printf("Please enter eight decimals.\n");
for (i = 0; i < 8; i++)
scanf("%lf", &array_1[i]);
array_2[0] = array_1[0];
for (i = 1; i < 8; i++)
{
array_2[i] = array_2[i - 1] + array_1[i];
}
printf("array:\n");
for (i = 0; i < 8; i++)
printf("%10.3f ", array_1[i]);
printf("\n");
for (i = 0; i < 8; i++)
printf("%10.3f ", array_2[i]);
printf("\n");
return 0;
}
 
