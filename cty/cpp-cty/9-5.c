#include<stdio.h>
void larger_of(double* a, double* b);
int main(void)
{
    double value_1, value_2;
 
    printf("Please enter two decimal numbers.\n");
    scanf("%lf %lf", &value_1, &value_2);
    printf("Originally x= %.3f y= %.3f\n", value_1, value_2);
    larger_of(&value_1, &value_2);
    printf("Now x= %.3f y=%.3f\n", value_1, value_2);
 
    return 0;
}
 
void larger_of(double* a, double* b)
{
    if (*a > * b)
        *b = *a;
    else
        *a = *b;
                     }
