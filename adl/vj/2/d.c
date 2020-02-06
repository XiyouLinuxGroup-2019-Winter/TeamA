#include <stdio.h>
#define min(a,b,c)  a<b?(a<c?a:c):b<c?b:c
int main()
{
    int dp[1500]={0};
    dp[0]=1;
    int a=0,b=0,c=0;
    for (int i = 1; i <= 1500; i++)
    {
        dp[i]=min(dp[a]*2,dp[b]*3,dp[c]*5);
        if(dp[i]==dp[a]*2)
            a++;
        if(dp[i]==dp[b]*3)
            b++;
        if(dp[i]==dp[c]*5)
            c++;
        

    }
    printf("%d",dp[1499]);
}