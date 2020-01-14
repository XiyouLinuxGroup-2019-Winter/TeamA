#include <iostream>
int main()
{
    const unsigned short ADD_SUBTRACT = 32;
    const double RATIO = 9.0 / 5.0;
    double tempIn,tempOut;
    char typein,typeout;
    std::cout<<"xx.x C or xx.c F ";
    std::cin>>tempIn >>typein;
    std::cin.ignore(100,'\n');
    std::cout<<"\n";
    switch (typein)
    {
    case 'C':
    case 'c':
        tempOut=tempIn*RATIO+ADD_SUBTRACT;
        typeout='F';
        typein='C';
       break;
    case 'f':
    case 'F':
        tempOut=(tempIn-ADD_SUBTRACT)/RATIO;
        typeout='C';
        typein='F';
        break;
        default:
        typeout='E';
        break;
    }
    if (typeout!='E')
    {
        std::cout<<tempIn<<typein
        <<" = "<<tempOut
        << typeout<<"\n\n";
    }
    else
    {
        std::cout<<"输入错误"<<"\n\n";
    }
    std::cout<<"请输入任意字符结束";
    std::cin.get();    
    
    return 0;
}