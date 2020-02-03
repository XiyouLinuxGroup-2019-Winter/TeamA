#include<stdio.h>
#define LENGTH 5
int max_sub(double* ar, int n);
int main(void)
{
    double arr[LENGTH];
    double* i;
 
    printf("Please enter five decimal.\n");
    for (i = arr; i < arr + LENGTH; i++)
        scanf("%lf", i);
    printf("The maximum subscript is %d\n", max_sub(arr, LENGTH));
 
    return 0;
}
 
int max_sub(double* ar, int n)
{
    double max = 0;
    int i;
    double* p;
 
    for (p = ar; p < ar + n; p++)
    {
        if (*p > max)
            max = *p;
    }
    for (i = 0; i < n; i++)
    {
        if (ar[i] == max)
            break;
    }
 
    return i;
}

