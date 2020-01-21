/*************************************************************************
	> File Name: 龙妈.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 02时00分27秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    /*int min=0,max=0;
    for(i=1;i<n;i++)
    {
        if(a[min]>=a[i])
            min=i;
    }
    int t;
    t=a[0];
    a[0]=a[min];
    a[min]=t;

    int t1;
    for(i=1;i<n;i++)
    {
        if(a[i]>=a[max])
        max=i;
    }
    t1=a[n-1];
    a[n-1]=a[max];
    a[max]=t1;

    int cnt=0;
    for(i=1;i<n-1;i++)
    {
        if(a[i]!=a[max] && a[i]!=a[min])
            cnt++;
    }*/
    int max=a[0];
    int min=a[0];
    int cnt=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]!=max && a[i]!=min)
            cnt++;
    }

    printf("%d",cnt);

}
