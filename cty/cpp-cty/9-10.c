#include<stdio.h>
void to_base_n(unsigned long n, int p);
int main(void)
{
    unsigned long number;
    int radix;
 
    printf("Please enter an integer and a radix(q to quit).\n");
    while (scanf("%lu %d", &number, &radix)==2)
    {
        if (radix < 2 || radix>10)
            printf("The radix must be between 2 and 10");
        else
        {
            printf("Conversion result: ");
            to_base_n(number, radix);
            putchar('\n');
        }
        printf("Enter an integer and a radix.(q to quit)\n");
    }
    printf("bye\n");
 
    return 0;
}
 
void to_base_n(unsigned long n, int p)
{
    int r;
 
    r = n % p;
    if (n >= p)
        to_base_n(n / p, p);
    printf("%d", r);
}
