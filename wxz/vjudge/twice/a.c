/*************************************************************************
	> File Name: a.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 16时07分56秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
int max(int a,int b)
{
    return a>b ? a : b;
}
int main()
{
    int dp[1000][1000];
    int V[1000];
    int W[1000];
    int v,w;
    int n;
    int i,j;
    scanf("%d",&n);
    while(n--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d %d",&w,&v);
        for(i=1;i<=w;i++)
            scanf("%d",&V[i]);
        for(i=1;i<=w;i++)
            scanf("%d",&W[i]);
        for(i=1;i<=w;i++)
        {
            for(j=0;j<=v;j++)
            {
                if(j>=W[i])
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-W[i]]+V[i]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        printf("%d\n",dp[w][v]);

    }
}
