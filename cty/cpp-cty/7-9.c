#include<stdio.h>
int main(void)
{
    unsigned int value, per, i;
    _Bool prime;
 
    printf("Please enter a positive integer: ");
    scanf("%u", &value);
    printf("Prime number:\n");
    for (per = 2; per <= value; per++)
    {
        for (prime = 1, i = 2; i * i <= per; i++)
        {
            if (per % i == 0)
                prime = 0;
        }
        if (prime == 1)
            printf("%u ", per);
    }
    putchar('\n');
 
    return 0;
}
