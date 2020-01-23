/*************************************************************************
	> File Name: s.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月21日 星期二 00时40分04秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n;
    int i;
    int t=0;
    scanf("%d",&n);
    int a[1000];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }

        }
    }
    if(n%2==0)
        printf("%d",a[n/2-1]);
    else
        printf("%d",a[n/2]);
}
