#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int p[n+1], d[n+1], dmax = 0;
        p[0]=0;d[0]=0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &p[i], &d[i]);
            dmax = dmax > d[i] ? dmax : d[i];
        }
        int dp[n+1][dmax + 1];
        for (int i = 0; i <= n; i++)
            memset(dp[i], 0, sizeof(dp[i]));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= dmax; j++)
            {
                if (j <= d[i])//i=4,d[i]=2
                    dp[i][j] = dp[i - 1][j] > dp[i - 1][j - 1] + p[i] ? dp[i - 1][j] : dp[i - 1][j - 1] + p[i];
                else
                    dp[i][j] = dp[i][j - 1];
            }
            printf("%d ",i);
            for (int j = 0; j <= dmax; j++)
            {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        printf("%d", dp[n - 1][dmax]);
    }
}//超过了天数