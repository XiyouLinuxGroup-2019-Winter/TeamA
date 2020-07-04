/*************************************************************************
	> File Name: c.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 20时42分08秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int min(int a,int b)
{
    return a>b?b:a;
}
int main()
{
    int dp[100000];
    int v[1000],w[1000];
    int n;
    int i,j;
    scanf("%d",&n);
    while(n--)
    {    
        int a,b;
        scanf("%d %d",&a,&b);
        int m;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d %d",&v[i],&w[i]);
        for(i=1;i<=b-a;i++)
            dp[i]=10000000;
        dp[0]=0;
        for(i=1;i<=m;i++)
        {
            for(j=w[i];j<=b-a;j++)
            {
                if(w[i]>j)
                    dp[j]=dp[j];
                else
                    dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        if(dp[b-a]==10000000)
            printf("This is impossible.\n");
        else
        printf("The minimum amount of money in the piggy-bank is %d.\n",dp[b-a]);
    }

}
