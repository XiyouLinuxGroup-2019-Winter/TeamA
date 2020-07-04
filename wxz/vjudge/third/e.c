/*************************************************************************
	> File Name: e.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 13时29分06秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n,m;
    int a[101][101];
    int b[101][101];
    int sum[101][101];
    int x;
    //int b[100][100];
    
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
           // scanf("%d",&x);
            //a[i][j]+=x;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&b[i][j]);
            sum[i][j]=a[i][j]+b[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%d ",sum[i][j]);
          printf("\n");
    }
}

