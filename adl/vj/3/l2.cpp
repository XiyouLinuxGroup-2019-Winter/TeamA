/* HDU1495 非常可乐 */
 
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
const int MAXN = 100;
 
int s, n, m, s2;
bool notvist[MAXN+1][MAXN+1][MAXN+1];
 
struct node {
    int s, n, m, level;
};
 
int bfs()
{
    if(s % 2 == 1)
        return -1;
 
    queue<node> q;
 
    s2 = s / 2;
    memset(notvist, true, sizeof(notvist));
 
    node f;
    f.s = s;
    f.n = 0;
    f.m = 0;
    f.level=0;
    q.push(f);
 
    notvist[f.s][f.n][f.m] = false;
 
    while(!q.empty()) {
        f = q.front();
        q.pop();
 
        if((f.s == f.n && f.s == s2) || (f.s == f.m && f.s == s2) || (f.m == f.n && f.m == s2))
            return f.level;
 
        node v;
 
        // s --> n
        if(f.s && n - f.n > 0) {
            if(f.s > n - f.n) {         // s > n的剩余容量
                v.s = f.s - (n - f.n);
                v.n = n;
                v.m = f.m;
            } else {                    // s <= n的剩余容量
                v.s = 0;
                v.n = f.n + f.s;
                v.m = f.m;
            }
            if(notvist[v.s][v.n][v.m]) {
                notvist[v.s][v.n][v.m] = false;
                v.level = f.level + 1;
                q.push(v);
            }
        }
        // s --> m
        if(f.s && m - f.m > 0) {
            if(f.s > m - f.m) {         // s > m的剩余容量
                v.s = f.s - (m - f.m);
                v.n = f.n;
                v.m = m;
            } else {                    // s <= m的剩余容量
                v.s = 0;
                v.n = f.n;
                v.m = f.m + f.s;
            }
            if(notvist[v.s][v.n][v.m]) {
                notvist[v.s][v.n][v.m] = false;
                v.level = f.level + 1;
                q.push(v);
            }
        }
        // n --> s
        if(f.n && s - f.s > 0) {
            if(f.n > s - f.s) {         // n > s的剩余容量
                v.s = s;
                v.n = f.n - (s - f.s);
                v.m = f.m;
            } else {                    // n <= s的剩余容量
                v.s = f.s + f.n;
                v.n = 0;
                v.m = f.m;
            }
            if(notvist[v.s][v.n][v.m]) {
                notvist[v.s][v.n][v.m] = false;
                v.level = f.level + 1;
                q.push(v);
            }
        }
        // n --> m
        if(f.n && m - f.m > 0) {
            if(f.n > m - f.m) {         // n > m的剩余容量
                v.s = f.s;
                v.n = f.n - (m - f.m);
                v.m = m;
            } else {                    // n <= m的剩余容量
                v.s = f.s;
                v.n = 0;
                v.m = f.m + f.n;
            }
            if(notvist[v.s][v.n][v.m]) {
                notvist[v.s][v.n][v.m] = false;
                v.level = f.level + 1;
                q.push(v);
            }
        }
        // m --> s
        if(f.m && s - f.s > 0) {
            if(f.m > s - f.s) {         // m > s的剩余容量
                v.s = s;
                v.n = f.n;
                v.m = f.m - (s - f.s);
            } else {                    // m <= s的剩余容量
                v.s = f.s + f.m;
                v.n = f.n;
                v.m = 0;
            }
            if(notvist[v.s][v.n][v.m]) {
                notvist[v.s][v.n][v.m] = false;
                v.level = f.level + 1;
                q.push(v);
            }
        }
        // m --> n
        if(f.m && n - f.n > 0) {
            if(f.m > n - f.n) {         // m > n的剩余容量
                v.s = f.s;
                v.n = n;
                v.m = f.m - (n - f.n);
            } else {                    // m <= n的剩余容量
                v.s = f.s;
                v.n = f.n + f.m;
                v.m = 0;
            }
            if(notvist[v.s][v.n][v.m]) {
                notvist[v.s][v.n][v.m] = false;
                v.level = f.level + 1;
                q.push(v);
            }
        }
    }
 
    return -1;
}
 
int main()
{
    while(scanf("%d%d%d", &s, &n, &m) != EOF) {
        if(s == 0 && n == 0 && m == 0)
            break;
 
        int ans = bfs();
 
        if(ans < 0)
            printf("NO\n");
        else
            printf("%d\n", ans);
    }
 
    return 0;
}