/*************************************************************************
	> File Name: h1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 14时58分20秒
 ************************************************************************/

#include<stdio.h>
#include <stdbool.h>
bool Prime(int n)
{
    int i;
    if(n==2)
        return true;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
            break;
    }
        if(n%i==0)
            return false;
        else
            return true;
}
int main()
{
    int a[10000];
    int i,j=0;
    int len=10000;
    int sum;
    int cnt=0,n;
    for(i=2;i<10000;i++)
    {
        if(Prime(i))
            a[j++]=i;
    }
    while(1)
    {
        cnt=0;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<len;i++)
        {
            sum=0;
            for(j=i;j<len;j++)
            {
                sum+=a[j];
                if(sum>n)
                    break;
                else if(sum==n)
                {
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n",cnt);
    }
}
