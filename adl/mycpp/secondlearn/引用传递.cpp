#include<iostream>

void swap(int &x,int &y);

int main(int argc, char const *argv[])
{
    int x,y;
    std::cout <<"请输入两个不同的值";
    std::cin>>x>>y;
    swap(x,y);
    std::cout<<"调换后输出："<<x<<' '<<y<<"\n\n";
    return 0;
}
void swap(int &x,int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}