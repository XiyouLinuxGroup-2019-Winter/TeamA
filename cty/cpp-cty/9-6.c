#include<stdio.h>
void sort(double* a, double* b, double* c);
void swap(double* x, double* y);
int main(void)
{
    double a, b, c;
 
    printf("Please enter three decimal numbers.\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Originally a= %.3f b= %.3f c=%.3f\n", a, b, c);
    sort(&a, &b, &c);
    printf("Now a= %.3f b=%.3f c=%.3f\n", a, b, c);
 
    return 0;
}
 
void sort(double* a, double* b, double* c)
{
    if (*a > * b)
        swap(a, b);
    if (*b > * c)
        swap(b, c);
    if (*a > * b)
        swap(a, b);
}
 
void swap(double* x, double* y)
{
    double temp;
 
    temp = *x;
    *x = *y;
    *y = temp;
}
