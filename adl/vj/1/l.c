#include <stdio.h>
int main()
{
    int n, a, b;
    while (scanf("%d", &n) != EOF)
    {
        if (n % 2 == 1)//5,
        {
            b = n / 2;//2
            a = b + 1;//3
            printf("%d\n",a*(a-1)/2+b*(b-1)/2);//1,3
        }
        else
        {
            b = n/2;//6.3
            printf("%d\n",b*(b-1));
        }
        
    }

    return 0;
}