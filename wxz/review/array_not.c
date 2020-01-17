/*************************************************************************
	> File Name: array_not.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 14时39分33秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n,m;
    int i,j;

    int c[20];

    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    scanf("%d",&m);
    int b[m];
    for(j=0;j<m;j++)
    scanf("%d",&b[j]);

    int flag=0;
    int count=0;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<m;j++)
        {
            if(a[i]==b[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            c[count]=a[i];
            count++;
        }
    }
    

    for(i=0;i<n;i++)//防止一个数组中前后出现相同的数字
    {
        flag=0;
        for(j=0;j<m;j++)
        {
            if(b[i]==a[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            c[count]=b[i];
            count++;
        }
    }
    printf("%d",c[0]);
    for(i=1;i<count;i++)
    {
        flag=0;
        for(j=0;j<i;j++)
        {
            if(c[i]==c[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf(" %d",c[i]);
    }

}
