#include <iostream>
#include <memory.h>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <math.h>
 
using namespace std;
 
typedef long long LL;
 
const int MAXN = 1e2 + 10;
const int MAXM = 1e5 + 10;
const int INF = 1e9;
 
int dp[MAXM];
int a[MAXN], b[MAXN];
 
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m), n|m)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1;i <= n;i++)
            scanf("%d", &a[i]);
        for (int i = 1;i <= n;i++)
            scanf("%d", &b[i]);
        for (int i = 1;i <= n;i++)
        {
            int k = 1;
            int v;
            while (k <= b[i])
            {
                v = k * a[i];
                b[i] -= k;
                for (int j = m;j >= v;j--)
                    dp[j] = max(dp[j], dp[j - v] + v);
                k = k << 1;
            }
            if (b[i] > 0)
            {
                k = b[i];
                v = k * a[i];
                for (int j = m;j >= v;j--)
                    dp[j] = max(dp[j], dp[j - v] + v);
            }
            for (int j = 0; j <= m; j++)
            {
                printf("%d ",dp[j]);
            }
            printf("\n");
        }
        int res = 0;
        for (int i = 1;i <= m;i++)
            if (dp[i] == i)
                res++;
        printf("%d\n", res);
    }
 
 
    return 0;
}