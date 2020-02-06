#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int t, n;
    double P;
    cin >> t;
    int m[101];
    double p[101];
    
    for (int i = 0; i < t; i++)
    {
        cin >> P >> n;
        int dp[110];
        memset(dp,0,sizeof(dp));
        memset(m, 0, sizeof(m));
        memset(p, 0, sizeof(p));
        for (int j = 0; j < n; j++)
        {
            cin >> m[j] >> p[j];
        }
        for (int j = 0; j < n; j++)
        {
            for (int k =  (int)(P*100); k >= (int)(p[j]*100); k--)
            {
                dp[k]=max(dp[k],dp[(k-(int)(p[j]*100))]+m[j]);
            }
            
        }
        printf("%d\n",dp[(int)(P*100)]);
    }
}