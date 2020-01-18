#include <stdio.h>
int main()
{
    int n, max = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        sum += b - a;
        if (sum > max)
            max = sum;
        
    }
    printf("%d",max);
}