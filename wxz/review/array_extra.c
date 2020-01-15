/*************************************************************************
	> File Name: array_extra.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 12时01分46秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n,m;
    int i,j,k;
    scanf("%d",&n);
    int a[10];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    scanf("%d",&m);
    int b[11];
    for(j=0;j<m;j++)
    scanf("%d",&b[j]);

    int c[21];
    for(k=0;k<n;k++)
    c[k]=a[k];

    for(j=0;j<m;j++,k++)
    c[k]=b[j];
    
    for(i=0;i<n+m;i++)
    {
        int c=0;
        for(j=1;j<=n+m;j++)
        {
            if(c[i]==c[j])
            c=1;
        }
        if(c==0)
        {
            printf("%d ",c[i]);
        }
    }
}
    

