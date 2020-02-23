/*************************************************************************
	> File Name: ruler_taking.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月11日 星期二 16时28分11秒
 ************************************************************************/

#include<stdio.h>
void sovle()
{
    int i=0,j=0,sum=0,ans=s;
    while(1)
    {
        while(j<n && sum<ans)
            sum+=a[j++];
        if(sum<ans)
            break;
        ans=min(ans,j-i+1);
        sum-=a[i++];

    }
    if(ans>n)
    ans=0;
}
