#include<stdio.h>
double power(double n, int p);
int main(void)
{
    double x, xpow;
    int exp;
 
    printf("Please enter a number and integer power(q to quit)\n");
    while (scanf("%lf %d", &x, &exp) == 2)
    {
        if (x == 0 && exp == 0)
            printf("0 to the power of 0 is undefined,processed as 1\n");
        else
        {
            xpow = power(x, exp);
            printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        }
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("bye\n");
 
    return 0;
}
 
double power(double n, int p)
{
    int per;
    double pow = 1;
 
    if (n == 0)
        return 0;
    if (p == 0)
        return 1;
    else if (p < 0)
    {
        for (per = 0; per < -p; per++)
            pow *= n;
        return 1 / pow;
    }
    else
    {
        for (per = 0; per < p; per++)
            pow *= n;
        return pow;
    }
}
