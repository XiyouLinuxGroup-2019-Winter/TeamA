#include<stdio.h>
int main()
{
    int a,b;
    int c[110];
    int sum=0;
    scanf("%d%d",&a,&b);
    int head=0,tail=a-1;
    for (int i = 0; i < a; i++)
    {
        scanf("%d",&c[i]);
    }
    for (int  i = 0; c[i]<=b&&head<=tail; i++)
    {
        head++;
        sum++;
    }
    for (int i = tail; c[i]<=b&&head<=tail; i--)
    {
        tail--;
        sum++;
    }
    printf("%d",sum);
    
    
    
    return 0;
}