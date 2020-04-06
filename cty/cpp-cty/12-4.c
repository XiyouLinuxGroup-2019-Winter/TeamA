#include<stdio.h>
int coun = 0;
 
void count(void);
int main(void)
{
    int n;
 
    printf("Please enter the number of cycle: ");
    scanf_s("%d", &n);
    for (; n > 0; n--)
        count();
 
    return 0;
}
 
void count(void)
{
    extern int coun;
    printf("Number of calls: %d\n", ++coun);
}
