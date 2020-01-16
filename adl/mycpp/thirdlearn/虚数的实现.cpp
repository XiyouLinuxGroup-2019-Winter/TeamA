#include <iostream>
class Complex
{
public:
    Complex(); //构造器1，无参数则初始化为0
    Complex(double r, double i);
    Complex complex_add(Complex &d);//引用传递
    void print();

private:
    double real;
    double imag;
};

Complex::Complex()
{
    real = 0;
    imag = 0;
}
Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}
    Complex Complex::complex_add(Complex &d)//注意返回值放在最前面，第二个Complex是类名
{
    Complex c;
    c.real=real+d.real;
    c.imag=imag+d.imag;
    return c;
    
}
void Complex::print()
{
    std::cout<<"("<<real<<","<<imag<<"i)\n";
}
int main()
{
    Complex c1(3,4),c2(5,-10),c3;
    c3 =c1.complex_add(c2);
    std::cout<<"c1= ";
    c1.print();
    std::cout<<"c2= ";
    c2.print();
    std::cout<<"c1+c2= ";
    c3.print();
    return 0;
}