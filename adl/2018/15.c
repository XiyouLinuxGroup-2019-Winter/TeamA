#include<stdio.h>
void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int n;
    scanf("%d",&n);
    int s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&s[i]);
    }
    
    for (int i = 1; i < n; i++)
    {
        if(i%2==0)
            swap(&s[i],&s[i/2]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d",s[i]);
    }
    
    
}