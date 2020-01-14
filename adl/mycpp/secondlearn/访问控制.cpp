#include<iostream>
#include<string>
//在编译的时候报错！！！
class Animal
{
public:
    Animal(std::string theName);//也就是说
    //可以在main函数里面用Animal("sad")
    //来填充name,当然可以填充更多的东西

    void eat();
    void sleep();
    void drool();
protected:
    std::string mouth;
private:
    std::string name;

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
Turtle::Turtle(std::string theName):Animal(theName)
{
}
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
    turtle.swim();
    return 0;
}