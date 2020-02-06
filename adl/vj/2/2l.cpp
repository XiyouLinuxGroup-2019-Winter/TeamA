#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct ss
{
    int p;
    int d;
} ss;
bool cmp(ss a, ss b)
{
    return a.p > b.p;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        ss s[n];
        int flag[n];
        int dmax = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &s[i].p, &s[i].d);
            dmax = max(s[i].d, dmax);
        }
        int day[dmax+1];//2+1
        memset(day, 0, sizeof(day));
        sort(s, s + n, cmp);
        // for(int i=0;i<n;i++)
        // printf("%d %d ",s[i].p,s[i].d);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int k = s[i].d;
            while (k > 0 && day[k])
                k--;
            if (k != 0)
            {
                sum += s[i].p;
                day[k] = 1;
            }
        }
        cout << sum << endl;
    }
}