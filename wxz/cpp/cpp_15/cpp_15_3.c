/*************************************************************************
	> File Name: cpp_15_3.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 11时01分59秒
 ************************************************************************/

#include<stdio.h>
int count_(int n);
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {

        printf("%d\n",count_(n));
    }
}
int count_(int n)
{
    int count=0;
    while(n)
    {
        count+=(n&1);
        n>>=1;
    }
    return count;
}
