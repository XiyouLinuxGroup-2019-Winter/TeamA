#include<stdio.h>
char y[]="XIyou",x[]="2018";
int main()
{
    char*const p1 = y;
    const char *p2 = y;
    p1=x;//顶层指针
    p2=x;
    *p1='x';
    *p2='x';//底层指针
}