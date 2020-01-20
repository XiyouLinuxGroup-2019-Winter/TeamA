/*************************************************************************
	> File Name: 海盗船与你.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 02时36分11秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i;
    int n,k;
    scanf("%d %d",&n,&k);
    int a[101];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int cnt=0;
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<=k)
            cnt++;
        else
            break;
    }
    
    for(int j=n-1;j>=0;j--)
    {
        if(a[j]<=k)
            cnt++;
        else
            break;
    }

    if(cnt>n)
    cnt=cnt/2;
    printf("%d",cnt);

}
