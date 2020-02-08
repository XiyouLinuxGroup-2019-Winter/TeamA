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
    int num;
    scanf("%d %d",&n,&m);
    char a[1000][1000];
    int i,j;
    for(i=0;i<n;i++)
        scanf("%s",a[i]);   
    
    int max;
    int cnt=0;
    int b[1000];
    for(j=0;j<m;j++)
    {
        max=0;
        for(i=0;i<n;i++)
        {
            if(max<a[i][j]-'0')
                max=a[i][j]-'0';
        }
        for(i=0;i<n;i++)
        {
            if(a[i][j]-'0'==max)
                b[i]=1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(b[i]==1)
        cnt++;
    }
    printf("%d",cnt);
}
