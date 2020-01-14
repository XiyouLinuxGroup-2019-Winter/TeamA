#include <iostream>
int main()
{
    const unsigned short ITEMS = 5;
    int intArray[ITEMS]={1,2,3,4,5};
    char charArray[ITEMS]={'F','i','s','h','C'};
    int *intPtr =intArray;
    char *charPtr =charArray;
    std::cout << "整形数据输出"<<'\n';
    for (int i = 0; i < ITEMS; i++)
    {
        std::cout<<*intPtr<<"at"<<reinterpret_cast
        <unsigned long>(intPtr)<<'\n';
        intPtr++;
    }
    std::cout<<"字符型数组输出"<<'\n';
    for (int i = 0; i < ITEMS; i++)
    {
        std::cout<<*charPtr<<"at"<<reinterpret_cast
        <unsigned long>(charPtr)<<'\n';
        charPtr++;
    }
    return 0;
}//说明了 reinterpret_cast 可以强制使得指针类型用
//cout打印出来，如果是c语言里面肯定会用%p,可以猜
//测这里是%c--->%p,但是为什么int型的指针就可以不用
//reinterpret_cast 就可以打印 指针了呢？？？