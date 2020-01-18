#include <stdio.h>
int main()
{
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int n, t, a, s = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a);
            s+=a;
        }
        printf("%d\n",s);
    }
}