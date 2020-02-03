#include<stdio.h>
#define LENGTH 5
double max_min(double* ar, int n);
int main(void)
{
    double arr[LENGTH];
    double* i;
 
    printf("Please enter five integers.\n");
    for (i = arr; i < arr + LENGTH; i++)
        scanf("%lf", i);
    printf("The difference between the maximum and minimum is %.2f\n", 
        max_min(arr, LENGTH));
 
    return 0;
}
 
double max_min(double* ar, int n)
{
    double max, min;
    double diff;
    double* p;
 
    for (p = ar, max = *p; p < ar + n; p++)
    {
        if (*p > max)
            max = *p;
    }
    for (p = ar, min = *p; p < ar + n; p++)
    {
        if (*p < min)
            min = *p;
    }
    diff = max - min;
 
    return diff;
}
