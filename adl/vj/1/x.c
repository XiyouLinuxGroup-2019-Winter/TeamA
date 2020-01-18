#include<stdio.h>
int main()
{
    int n;
    int max=0;
    int min=999999999;
    scanf("%d",&n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&v[i]);
        if(max<v[i])
            max=v[i];
        if(min>v[i])
            min=v[i];
    }
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        if(v[i]==max||(v[i]==min))
        {
            sum++;
        }
    }
    printf("%d",n-sum);
    
    
    return 0;
}