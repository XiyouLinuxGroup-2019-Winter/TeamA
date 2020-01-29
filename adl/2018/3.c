#include<stdio.h>
static int a=2018;
static void func()
{
    static int b;
    printf("a=%d,b=%d",a++,++b);
}
int main()
{
    func();
    func();
    func();
}