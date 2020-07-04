/*************************************************************************
	> File Name: array_joint.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 22时17分42秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[4];
    int b[5];
    int c[9];
    int i,j,k,t;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(j=0;j<m;j++)
    scanf("%d",&b[j]);
    for(k=0;k<n;k++)
    c[k]=a[k];
    //k++;
    for(j=0;j<m;j++,k++)
    {
        c[k]=b[j];
    }
    for(i=0;i<(n+m-1);i++)
    {
        for(j=0;j<(n+m-i-1);j++)
        {
            if(c[j]>c[j+1])
            {
                t=c[j];
                c[j]=c[j+1];
                c[j+1]=t;
            }
        }
    }
    for(i=0;i<(n+m);i++)
    printf("%d ",c[i]);
}
