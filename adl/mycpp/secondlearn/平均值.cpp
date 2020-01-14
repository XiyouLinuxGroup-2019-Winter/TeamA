#include <iostream>
// #define ITEM 10
int main()
{
     const unsigned short ITEM =10;
    int num[ITEM];
    std::cout << "请输入"<<ITEM<<"个整型数据！\n\n";
    for (int i = 0; i < ITEM; i++)
    {
        std::cout << "请输入第" << i + 1 << "个数据";
        while(!(std::cin >> num[i]))
        {
            std::cin.clear();
            std::cin.ignore(100,'\n');
            std::cout<<"请输入一个合法的值";            
        }
    }
    int total =0;
    for (int j = 0; j < ITEM; j++)
    {
        total+=num[j];
    }
    std::cout<<"总和是"<<total<<"\n";
    std::cout<<"平均值是"<<(float)total/10<<"\n";
    return 0;
}