#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int *)b;
}
int main()
{
    int n;
    int s[1000010];
    scanf("%d",&n);
    int head=0;
    int tail=n-1;
    for (int  i = 0; i < n; i++)
    {
        scanf("%d",&s[i]);
    }
    int flag=1;
    qsort(s,n,sizeof(int) ,&cmp);
    while (tail!=head)
    {
        if(flag==1)
            {tail--;
            flag=0;}
        else
            {head++;
            flag=1;}        
        
    }
    printf("%d",s[tail]);
    
}