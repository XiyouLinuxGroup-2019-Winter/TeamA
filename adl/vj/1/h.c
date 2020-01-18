#include <stdio.h>
int main()
{
    int n, m, s=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &m);
            sum += m;
        }
        if (sum >= 2)
            s++;
    }
    printf("%d",s);
    return 0;
}