#include <iostream>
#include <string>

class Pet
{
public:
    Pet(std::string theName);

    void eat();
    void sleep();
   virtual void play();

protected:
    std::string name;
};

class Cat : public Pet
{
public:
    Cat(std::string theName);
    void climb();
    void play();
};

class Dog : public Pet
{
public:
    Dog(std::string theName);
    void bark();
    virtual void play();
};

Pet::Pet(std::string theName)
{
    name = theName;
}
void Pet::eat()
{
    std::cout << name << "eating\n";
}
void Pet::sleep()
{
    std::cout << name << "sleeping\n";
}
void Pet::play()
{
    std::cout << name << "playing\n";
}
Cat::Cat(std::string theName) : Pet(theName)
{
}
void Cat::climb()
{
    std::cout << name << "爬树\n";
}
void Cat::play()
{
    Pet::play();
    std::cout << name << "吸猫\n";
}
// void Cat::eat()
// {
//     std::cout<<name<<"吃法不同\n";
// }
Dog::Dog(std::string theName) : Pet(theName)
{
}
void Dog::bark()
{
    std::cout << name << "叫\n";
}
void Dog::play()
{
    Pet::play();
    std::cout << name << "玩狗\n";
}
int main()
{
    Pet asdd("asd");
    Pet *cat = new Cat("加菲");
    Pet *dog = new Dog("dodog");
     Cat *asd =new Cat("ADL");
     asdd.play();
     asd->climb();
    cat->sleep();
    cat->eat();
    cat->play();
    dog->eat();
    dog->play();
    dog->sleep();
    delete cat;
     delete asd;
    delete dog;
    return 0;
}