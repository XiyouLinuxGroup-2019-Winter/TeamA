#include<stdio.h>
#define LENGTH 5
void re_order(double* ar, int n);
int main(void)
{
    double arr[LENGTH];
    double* p;
 
    printf("Please enter five decimals.\n");
    for (p = arr; p < arr + LENGTH; p++)
        scanf("%lf", p);
    printf("Original array: ");
    for (p = arr; p < arr + LENGTH; p++)
        printf("%.2f ", *p);
    putchar('\n');
 
    re_order(arr, LENGTH);
    printf("Current array: ");
    for (p = arr; p < arr + LENGTH; p++)
        printf("%.2f ", *p);
    putchar('\n');
 
    return 0;
}
 
void re_order(double* ar, int n)
{
    int i;
    double temp;
 
    for (i = 0; i < n / 2; i++)
    {
        temp = ar[i];
        ar[i] = ar[n - i - 1];
        ar[n - i - 1] = temp;
    }
}
