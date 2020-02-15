#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
#define min(x, y) ((x )>( y) ?( y) :( x))
#define max(x, y)(( x) >( y )? (x ):( y))
int ans;
int n, c;
int *book;
int *x;

int main()
{
    //printf("%d",1%1);
    int n, m, s;
    while (scanf("%d%d%d", &s, &n, &m) == 3 && (s != 0 || n != 0 || m != 0))
    {
        if(s!=n+m)
        {
            printf("NO\n");
            continue;
        }
        if (s % 2 == 1)
        {
            printf("NO\n");
            continue;
        }
        int mid = s / 2;

        if ((max(m, n) - mid) % min(m, n) != 0)
        {
          // printf("%d %d %d %d", max(m, n) - mid, min(m, n), mid, (max(m, n) - mid) % min(m, n));
            printf("NO\n");
            continue;
        }
        printf("%d\n", 1 + (max(m, n) - mid) / min(m, n) * 2);
    }
}