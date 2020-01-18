#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int  i = 0; i < n; i++)
    {
        printf("%c",i%m+'a');
    }
    
}