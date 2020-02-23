#include <iostream>
#include <cstring>
#include<cstdio>
char map[8][8];
int book[8];
int ans;
int n, k;
bool judge(int x, int y)
{
    if (book[y] == 1)
        return false;
    return true;
}
void dfs(int x, int kk)
{
    if (kk == 0)
    {
        ans++;
        return;
    }
    for (int i = x; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!book[j] && (map[i][j] == '#'))
            {
                book[j] = 1;
                dfs(i + 1, kk - 1);
                book[j]=0;
            }
        }
    }
}
int main()
{
    while (scanf("%d%d", &n, &k) && (n != -1 || k != -1))
    {
           ans=0;
        memset(book, 0, sizeof(book));
        for (int i = 0; i < n; i++)
                scanf("%s", map[i]);
        dfs(0, k);
        printf("%d\n",ans);
    }
}