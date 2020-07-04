/*************************************************************************
	> File Name: bucket_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 00时06分07秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    int a[1000],n,i,t;
    for(i=0;i<1000;i++)
    a[i]=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        a[t]=1;
    }
    for(i=0;i<1000;i++)
    {
        if(a[i]==1)
        {
            printf("%d",i);
        }
    }
}
