/*************************************************************************
	> File Name: 杨辉三角.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 18时58分54秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n;
   while(scanf("%d",&n)!=EOF)
    {
        int a[100][100];
        int i,j;
        for(i=1;i<=n;i++)
        {
            a[i][1]=1;
            a[i][i]=1;
        }
        for(i=3;i<=n;i++)
        {
            for(j=2;j<n;j++)
                a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            printf("%d ",a[i][j]);
            printf("%d\n",a[i][i]);
        }
        printf("\n");
    }
}
