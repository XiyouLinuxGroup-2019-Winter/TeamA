/*************************************************************************
	> File Name: 完美人生没考试.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 01时28分49秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    int a[n][101];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    
    int max;
    int cnt=0;
    for(j=0;j<m;j++)
    {
        max=a[0][m];
        for(i=0;i<n;i++)
        {
            if(max<a[i][j] && max!=a[i][i])
                cnt++;
            if(max>a[i][j] && )
                cnt++;
            if(max=a[i][j])
                break;
        }
    }
    printf("%d",cnt);
}
