/*************************************************************************
	> File Name: 2018_3.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月25日 星期六 23时36分12秒
 ************************************************************************/

#include<stdio.h>
static int a=2018;
static void func()
{
    static int b;
    printf("a=%d,b=%d\n",a++,++b);
}
int main()
{
    func();
    func();
    func();
}
