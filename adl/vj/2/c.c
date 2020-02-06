#include <stdio.h>
#include<string.h>
#define min(x, y) (x) < (y) ? (x) : (y)

int main()
{
    int t, e, n, f;
    int p[50001] = {0};
    int w[50001] = {0};
    int dp[50000];
    scanf("%d", &t);
    while (t--)
    {   memset(dp,0x3f3f3f,sizeof dp);
        scanf("%d%d", &e, &f);
        int A = f - e;
        scanf("%d", &n);
        dp[0]=0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &p[i], &w[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = w[i]; j <= f-e; j++)
            {
                dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
            }
            // for (int j = 0; j < f-e; j++)
            // {
            //     printf("%d ",dp[j]);
            // }
            // printf("\n");   
        }
        if(dp[f-e]!=0x3f3f3f3f)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f-e]);
        else
            printf("This is impossible.\n");
    }
}