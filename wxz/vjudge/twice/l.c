/*************************************************************************
	> File Name: l.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 21时42分35秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
struct node{
    int di,pi;
};
int main()
{
    int b[10005];
    struct node a[10005];
    struct node t;
    int i,j;
    int n;
   
    while(~scanf("%d",&n))
    {
        int sum=0;
        
        for(i=0;i<n;i++)
            scanf("%d %d",&a[i].pi,&a[i].di);
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i].pi<a[j].pi)
                {
                    t=a[j];
                    a[j]=a[i];
                    a[i]=t;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=a[i].di;j>=1;j--)
            {
                if(!b[j])
                {
                    b[j]=1;
                    sum+=a[i].pi;
                    break;
                }
            }
        }
        printf("%d\n",sum);
    }
}
