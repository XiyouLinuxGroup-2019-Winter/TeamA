#include <stdio.h>
#define max(x, y) (x) > (y) ? (x) : (y)
#include <string.h>
int main()
{
    int t, n, s;
    int c[1010] = {0};
    int v[1010] = {0};

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {

        scanf("%d%d", &n, &s); //个数，容量
        int sum[s+1];
        memset(sum,0,sizeof(sum));
        
        for (int j = 0; j < n; j++)
            scanf("%d", &c[j]); //价值
        for (int j = 0; j < n; j++)
            scanf("%d", &v[j]); //配重
        for (int j = 0; j < n; j++)
        {
            for (int k =s;k>=v[j];k--)
                sum[k] = max(sum[k], sum[k - v[j]] + c[j]);
        }
        printf("%d\n",sum[s]);
    }
}