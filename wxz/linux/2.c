/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 00时17分41秒
 ************************************************************************/

#include<stdio.h>
int main(int argc,char *argv[])
{
    int a[3][4];
    printf("%p\n%p\n%p\n%p\n%p\n%p\n",&a[0][0],a[0],a,a[0]+1,a+1,a[1]);
    return 0;
}

