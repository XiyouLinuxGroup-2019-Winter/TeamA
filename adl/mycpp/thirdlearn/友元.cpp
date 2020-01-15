#include <iostream>
#include <string>

class Lovers
{
public:
    Lovers(std::string theName);//构造器申明
    void kiss(Lovers *lover);//方法申明，这里的Lovers也就是类
    //实参填入的是之后定义的A，B
    void ask(Lovers *lover, std::string something);//方法申明

protected:
    std::string name;

    friend class Others;
};

class Boyfriend : public Lovers//继承
{
public:
    Boyfriend(std::string theName);//构造器申明
};

class Girlfriend : public Lovers//继承
{
public:
    Girlfriend(std::string theName);//构造器申明
};

class Others//(友元)不用继承
{
public:
    Others(std::string theName);//构造器申明
    void kiss(Lovers *lover);
    void ask(Lovers  *lover);//
    void play(Lovers*lover1,Lovers*lover2);
protected:
    std::string name;
};

Lovers::Lovers(std::string theName)//构造器定义
{
    name = theName;
}
void Lovers::kiss(Lovers *lover)//方法定义
{
    std::cout << name << "kisss" << lover->name << std::endl;
}
void Lovers::ask(Lovers *lover, std::string something)//方法定义
{
    std::cout << "askask" << std::endl;
}
Boyfriend::Boyfriend(std::string theName) : Lovers(theName)//子类构造器定义
{
}
Girlfriend::Girlfriend(std::string theName) : Lovers(theName)//子类构造器定义
{
}
Others::Others(std::string theName) //构造器定义，这里不用继承
{
    name = theName;
}
void Others::kiss(Lovers *lover)//方法定义，说明了友元的作用不过是访问Lovers成员
{
    std::cout << name << "kiss" << lover->name << std::endl;//上面用指针，下面用->
}
void Others::ask(Lovers *lover)
{
    std::cout<<name <<"askaskaskaskask"<<lover->name<<std::endl;
}
void Others::play(Lovers *lover1,Lovers *lover2)
{
    std::cout<<name<<"playwith"<<lover1->name<<"and"<<lover2->name<<std::endl;
}
int main()
{
    Boyfriend boyfriend("A");
    Girlfriend girlfriend("B");
    Others others("CC");
    girlfriend.kiss(&boyfriend);
    girlfriend.ask(&boyfriend, "doa");
    std::cout << "lvlvlv";
    others.kiss(&girlfriend);
    others.ask(&boyfriend);
    others.play(&girlfriend,&boyfriend);
}