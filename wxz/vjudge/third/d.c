/*************************************************************************
	> File Name: d.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 14时27分44秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int a[1001];
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;

            }
            
        }
    }
    int ans=a[n-1]-a[0]+1-n;
    printf("%d\n",ans);
}
