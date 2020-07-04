/*************************************************************************
	> File Name: selecte_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 22时12分04秒
 ************************************************************************/

#include<stdio.h>
void selectionsort(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]<a[j])
            {
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
}
int main()
{
    int a[5]={1,2,5,3,0};
    int i;
    selectionsort(a,5);
    for(i=0;i<5;i++)
    printf("%d ",a[i]);
}
