#include<stdio.h>
double h_average(double a, double b);
int main(void)
{
    double value_1, value_2;
 
    printf("Please enter two decimal numbers.\n");
    scanf("%lf %lf", &value_1, &value_2);
    printf("Harmonic average:  %f\n",h_average(value_1,value_2));
 
    return 0;
}
 
double h_average(double a, double b)
{
    double average;
 
    average = ((1 / a) + (1 / b)) / 2;
 
    return 1 / average;
}
