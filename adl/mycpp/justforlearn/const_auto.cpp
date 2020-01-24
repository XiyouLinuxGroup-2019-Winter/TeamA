#include <iostream>

int main()
{
    int i=0,&r=i;
    auto a=r;
    const int ci=i,&cr=ci;
    const int ci=i,&cr=ci;
    auto b=ci;//auto--int
    auto c=cr;//auto--int
    auto d=&i;//auto--int
    auto e=&ci;//auto--const --int
    const auto f=ci;//const auto int
    auto &g=ci;//auto--const int
    //auto &h=42;//nitial value of reference to non-const must be an lvalue
    const auto &j=42;//const auto int
    auto k=ci,&l=i;//k---int,l----int
   // auto &n=i,/* int */ *p2=&ci;//'auto' type is "const int" for this entity, but was previously implied to be "int"
    

}
/*auto忽略顶层const,保留底层const
并且只看引用的初始元素的类型*/