#include<stdio.h>
int main()
{
    int a=1;
    printf("%p\n",&a);
    int val=2018;
    int *pi=140731476892776;
    
    *pi=0;
    printf("%d",a);
}