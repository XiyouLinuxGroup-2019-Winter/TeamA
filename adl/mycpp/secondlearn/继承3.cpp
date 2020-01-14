#include <iostream>
#include <string>

class BaseClass
{
public:
        BaseClass();
        ~BaseClass();
        void doSomething();
};
class SubClass:public BaseClass
{
public:
    SubClass();
    ~SubClass();
};

BaseClass::BaseClass()
{
    std::cout<<"进入基类构造器";
    std::cout<<"dosomething\n\n";
}
BaseClass::~BaseClass()
{
    std::cout<<"进入基类析构器";
    std::cout<<"dosomething\n\n";
}
void BaseClass::doSomething()
{
    std::cout<<"doeeee\n\n";
}
SubClass::SubClass()
{
    std::cout<<"进入子类构造器\n";
    std::cout<<"doeeeeeee\n\n";
}
SubClass::~SubClass()
{
    std::cout<<"进入子类析构器\n";
    std::cout<<"do odododood\n\n";
}
int main()
{
    SubClass subclass;
    subclass.doSomething();
    std::cout<<"bye\n";
    return 0;
}