#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&(n!=0||m!=0))
    {
        int a[n],c[n];
        int dp[m+1];
      
        memset(dp,0,sizeof(dp));
          dp[0]=1;
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]);//面值
        for (int i = 0; i < n; i++)
            scanf("%d",&c[i]);//个数
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k <= c[i]; k++)
            {
                for (int j = m; j >=k*a[i]; j--)
                {
                    dp[j]=max(dp[j],dp[j-k*a[i]]+k);
                }
                
            }
            
            for (int j = 0; j <= m; j++)
            {
                printf("%d ",dp[j]);
            }
            printf("\n");
        }
        int sum=0;

        for (int i = 1; i <= m; i++)
        {
        //    printf("%d",dp[i]);
            sum+=dp[i];
        }
        printf("%d\n",sum);
        
        
        //dp[j]=dp[j]+dp[j-c[i]]
        
    }
    return 0;
}