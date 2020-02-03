#include<stdio.h>
double min(double x, double y);
int main(void)
{
    double value_1, value_2;
 
    printf("Please enter two decimal numbers.\n");
    scanf("%lf %lf", &value_1, &value_2);
    printf("The smallest is %f\n", min(value_1, value_2));
 
    return 0;
}
 
double min(double x, double y)
{
    return x < y ? x : y;
}
