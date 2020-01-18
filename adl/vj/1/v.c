#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int*s;
    int max=0,min=2101;
    scanf("%d",&n);
    s=(int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&s[i]);
        if(s[i]>max)max=s[i];
        if(s[i]<min)min=s[i];
    }
    int m=(max+min)/2;
    printf("%d",m);
    
    
    return 0;
}