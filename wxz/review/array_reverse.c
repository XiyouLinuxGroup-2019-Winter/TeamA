/*************************************************************************
	> File Name: array_reverse.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 22时05分35秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n;
    int i,j;
    int a[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(j=n-1;j>=0;j--)
    printf("%d ",a[j]);
    putchar('\n');
}
