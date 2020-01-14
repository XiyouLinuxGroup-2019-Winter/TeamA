#include<iostream>
#include<string>
int main()
{
    std::string str;
    std::cout <<"请随便输入一个字符串";
    std::getline(std::cin,str);
    std::cout<<str<<"\n";
    return 0;
}