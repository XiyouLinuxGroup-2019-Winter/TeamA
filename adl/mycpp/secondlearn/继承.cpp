#include<iostream>
#include<string>

class Animal
{
public:
    std::string mouth;
    void eat();
    void sleep();
    void drool();
};

class Pig:public Animal
{
public:
        void climb();
};
class Turtle:public Animal
{
public:
        void swim();
};
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
void Pig::climb()
{
    std::cout<<"爬树"<<"\n";
}
void Turtle::swim()
{
    std::cout<<"游"<<std::endl;
}
int main()
{
    Pig pig;
    Turtle turtle;
    pig.eat();
    turtle.eat();
    pig.climb();
    turtle.swim();
    return 0;
}