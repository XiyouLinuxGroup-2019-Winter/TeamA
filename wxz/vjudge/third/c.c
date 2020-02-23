/*************************************************************************
	> File Name: c.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 03时17分23秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int n,k,cnt;
char a[10][10];
int b[100];
void dfs(int x,int y)
{
    int i,j;
    if(k==y)
    {
        cnt++;
    }
    else
    {
        for(i=x;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='#' && b[j]==0)
                {
                    b[j]=1;
                    dfs(i+1,y+1);
                    b[j]=0;
                }

            }

        }

    }
}
int main()
{
    while(1)
    {
        int i,j;
        scanf("%d %d",&n,&k);
        if(n==-1 && k==-1)
            break;
       // memset(a,'\0',sizeof(a));
        memset(b,0,sizeof(b));
        cnt=0;
        for(i=0;i<n;i++)
        {
            getchar();
            for(j=0;j<n;j++)
                scanf("%c",&a[i][j]);
        }
        dfs(0,0);
        printf("%d\n",cnt);
    }
}
