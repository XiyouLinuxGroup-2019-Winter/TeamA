#include<iostream>
class Complex
{
    public:
        Complex();
        Complex(double r,double i);
        Complex operator+(Complex &d);
        void print();
    private:
        double real;
        double imag;
};
Complex::Complex()
{
    real=0;
    imag=0;
}
Complex::Complex(double R,double I)
{
    real=R;
    imag=I;
}
Complex Complex::operator+(Complex &d)
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
    c3=c1+c2;
    std::cout<<"c1=";
    c1.print();
    std::cout<<"c2=";
    c2.print();
    std::cout<<"c1+c2=";
    c3.print();   
}