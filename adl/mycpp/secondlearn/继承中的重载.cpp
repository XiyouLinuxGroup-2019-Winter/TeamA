#include<iostream>
#include<string>

class Animal
{
public:
    std::string mouth;
    std::string name;
    Animal(std::string theName);//也就是说
    //可以在main函数里面用Animal("sad")
    //来填充name,当然可以填充更多的东西
    
    void eat();
    void eat(int eatcount);
    void sleep();
    void drool();
};

class Pig:public Animal
{
public:
        
        void climb();
        Pig(std::string theName);
};
class Turtle:public Animal
{
public:
        
        void swim();
        Turtle(std::string theName);
};
 
 Animal::Animal(std::string theName)
 {
     name=theName;
 }

void Animal::eat()
{
    std::cout<<"i m eatting!"<<std::endl;
}
void Animal::eat(int eatcount)
{
    std::cout<<name<<"have eat "<<eatcount<<"碗"<<"\n";
}
void Animal::sleep()
{
    std::cout<<"i'm sleeping"<<std::endl;
}
void Animal::drool()
{
    std::cout<<"i'm drooling"<<std::endl;
}
//其实这里考虑的是子类构造器和基类构造器都有
//参数的情况
//因为析构器没有参数，所以没写析构子函数，当然
//想写也可以，见继承3.cpp
Pig::Pig(std::string theName):Animal(theName)
{

}
void Pig::climb()
{
    std::cout<<"爬树"<<"\n";
}
// void Pig::eat()
// {
//     Animal::eat();
//     std::cout<<name<<"正在吃鱼\n\n";
// }
Turtle::Turtle(std::string theName):Animal(theName)
{
}
// void Turtle::eat()
// {
//     Animal::eat();
//     std::cout<<name<<"正在吃屎\n\n";
// }
void Turtle::swim()
{
    std::cout<<"游"<<std::endl;
}
int main()
{
    Pig pig("小猪猪");
    Turtle turtle("小甲鱼");
    std::cout<<"这只猪的名字"<<pig.name<<std::endl;
    std::cout<<"乌龟的名字"<<turtle.name<<std::endl;
    pig.eat();
    turtle.eat();
    pig.climb();
    pig.eat(3);
    turtle.swim();
    return 0;
}//注：animal上重载的函数（方法）依旧可以被子类
//的方法所覆盖！！！