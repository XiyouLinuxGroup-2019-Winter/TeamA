#include <iostream>
#include <cstdio>
#include <cstring>
#define max(x, y) (x) > (y) ? (x) : (y)

using namespace std;
int main()
{
    int t, n;
    cin >> t;
    double P;
    while (t--)
    {
        double dp[10010] = {0};
        int m[110] = {0};
        double p[110] = {0};
        cin >> P >> n;
        P = 1 - P;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> m[i] >> p[i];
            sum += m[i];
            p[i] = 1 - p[i];
        }
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = sum; j >= m[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - m[i]] * p[i]);
            }
        }
        for (int i = sum; i >= 0; i--)
        {
            if (dp[i] >= P)
            {
                cout << i << endl;
                break;
            }
        }
    }
}