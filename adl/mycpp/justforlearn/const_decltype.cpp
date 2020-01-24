#include <iostream>
int main()
{
    const int ci=0,&cj=ci;
    decltype(ci)x=0;//const int 
    decltype(cj)y=x;//const int &cj
    //decltype(cj)z;  //reference variable "z" requires an initializer,需要初始化
    int i=42,*p=&i,&r=i;
    decltype(r)b=i;
    decltype(r+0)b;
    decltype(*p)c=i;//第一次听说解引用指针可以得到指针的对象而且还可以给这个对象赋值，于是 decltype(*p)竟然是int&,而不是int
    decltype((i))q=i;
    
    decltype(i) e;
}

