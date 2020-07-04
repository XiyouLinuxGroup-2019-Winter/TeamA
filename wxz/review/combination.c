/*************************************************************************
	> File Name: combination.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 22时14分54秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    int i,j;
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {        
            if(i!=j)
                sum+=a[i]*10+a[i];
        }
    }
    printf("%d",sum);
}
