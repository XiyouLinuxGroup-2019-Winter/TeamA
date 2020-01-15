#include <iostream>
#include <string>
class Pet
{
public:
    Pet(std::string theName);
    ~Pet();
    static int getCount();

protected:
    std::string name;

private:
    static int count;
};

class Dog : public Pet
{
public:
    Dog(std::string theName);
};
class Cat : public Pet
{
public:
    Cat(std::string theName);
};
int Pet::count = 0;
Pet::Pet(std::string theName)
{
    name = theName;
    count++;
    std::cout << "the cute pet birth,name is" << name << "\n";
}
Pet::~Pet()
{
    count--;
    std::cout << name << "die\n";
}
int Pet::getCount()
{
    return count;
}
Dog::Dog(std::string theName) : Pet(theName)
{
    std::cout<<"this"<<this<<"\n";
}
Cat::Cat(std::string theName) : Pet(theName)
{
}
int main()
{
    Dog dog("Tom");
    Cat cat("Jerry");
    std::cout<<"dog:"<<&dog<<"\n";
    std::cout << "\n已经诞生了" << Pet::getCount() << "只宠物！\n\n";
    {
        Dog dog_2("tom2");
        Cat cat_2("jerry2");
        std::cout << "\n已经诞生了" << Pet::getCount() << "只宠物！\n\n";
    }
    std::cout<<"\nAND NOW BACK TO "<<Pet::getCount()<<"pet!\n\n";
    return 0;
}