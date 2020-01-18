/*************************************************************************
	> File Name: 电车哈士奇.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 10时52分31秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][2],b[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int sum=0;
    int max=0;
    for(i=0,j=0;i<n;i++)
    {
        sum=sum+a[i][1]-a[i][0];
        if(sum>max)
            max=sum;
    }
    printf("%d",max);
}
