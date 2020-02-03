
#include<stdio.h>
#define LENGTH 5
int int_max(int* ar,int n);
int main(void)
{
    int arr[LENGTH];
    int* i;
 
    printf("Please enter five integers.\n");
    for (i = arr; i < arr + LENGTH; i++)
        scanf("%d", i);
    printf("The largest is %d\n", int_max(arr,LENGTH));
 
    return 0;
}
 
int int_max(int *ar,int n)
{
    int max = 0;
    int* p;
 
    for (p = ar; p < ar + n; p++)
    {
        if (*p > max)
            max = *p;
    }
 
    return max;
}
