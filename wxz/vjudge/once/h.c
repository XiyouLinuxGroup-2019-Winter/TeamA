/*************************************************************************
	> File Name: 三人行.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 12时41分22秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int a[1001][3];
    int i,j;
    int n;
    scanf("%d",&n);
    int cnt=0;
    int cnt1=0;
    getchar();
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]==1)
                cnt++;       
        } 
        if(cnt>=2)
        {
            cnt1++;
        }
        cnt=0;
    }
    printf("%d",cnt1);
}
