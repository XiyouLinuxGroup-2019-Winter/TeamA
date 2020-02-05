#include<stdio.h>
unsigned int fibonacci(int n);
int main(void)
{
    int n;
 
    printf("Please enter the number of terms in the Fibonacci sequence(q to quit): ");
    while (scanf("%d", &n))
    {
        if (n <= 0)
            printf("Please enter a positive integer.\n");
        else
            printf("Value: %lu\n", fibonacci(n));
        printf("Enter the number of terms: ");
    }
    printf("bye\n");
 
    return 0;
}
 
unsigned int fibonacci(int n)
{
    unsigned int last_1 = 1;
    unsigned int last_2 = 1;
    unsigned int value;
    int per;
 
    if (n == 1 || n == 2)
        return 1;
    else
    {
        for (per = 3; per <= n; per++)
        {
            value = last_1 + last_2;
            last_1 = last_2;
            last_2 = value;
        }
    }
 
    return value;
}
