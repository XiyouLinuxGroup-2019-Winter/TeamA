/*************************************************************************
	> File Name: bubble_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 22时07分45秒
 ************************************************************************/

#include<stdio.h>
void bubblesort(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
int main()
{
    int i;
    int a[5]={3,5,8,2,1};
    bubblesort(a,5);
    for(i=0;i<5;i++)
    printf("%d ",a[i]);
}
