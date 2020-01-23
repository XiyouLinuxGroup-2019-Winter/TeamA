/*************************************************************************
	> File Name: cpp_15_4.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 11时46分17秒
 ************************************************************************/

#include<stdio.h>
int return_(int n,int bit);
int main()
{
    int n=return_(1,0);
    printf("%d\n",n);
}
int return_(int n,int bit)
{
    return (n & (1<<(bit-1)));
}
