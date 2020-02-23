/*************************************************************************
	> File Name: h.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 05时16分23秒
 ************************************************************************/

#include<stdio.h>
#include <stdbool.h>
//#include <algorithm>
using namespace std;
int max=10000;
int n,c;
int a[1000000];
bool judge(int x)
{
    int tail=0;
    for(int i=0;i<c;i++)
    {
        int cnt=tail+1;
        while(cnt<n && a[cnt]-a[tail]<x)
            cnt++;
        if(cnt==n)
            return false;
        tail=cnt;
    }
    return true;
}
int main()
{
    scanf("%d %d",&n,&c);
    int i,j;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    /*for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]<a[j])
                {
                    int t=a[j];
                    a[j]=a[i];
                    a[i]=t;
                }
            }
        }*/
    sort(a,a+n);
    int start=0;
    int end=a[n-1]-a[0];
    int mid,ans;
    while(end>=start)
    {
        mid=(start+end)/2;
        if(judge(mid))
        {
            ans=mid;
            start=mid+1;
        }
        else
            end=mid-1;
    }
    printf("%d\n",end);
}

