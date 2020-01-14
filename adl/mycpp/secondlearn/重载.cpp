#include<iostream>
float calc(float a);
float calc(float a,float b);
float calc(float a,float b, float c);
int main()
{
    float t1,t2,t3;
    
    std::cout<<"there is the first way,please input 1 numbers"<<std::endl;
    std::cin>>t1;
    std::cout<<"the first answer is"<<calc(t1)<<std::endl;
    std::cout<<"there is the second way,please input 2 numbers"<<std::endl;
    std::cin>>t1>>t2;
    std::cout<<"the second answer is"<<calc(t1,t2)<<std::endl;
    std::cout<<"there is the third way,please input 3 numbers"<<std::endl;
    std::cin>>t1>>t2>>t3;
    std::cout<<"the third answer is"<<calc(t1,t2,t3)<<std::endl;
    
    return 0;
}
float calc(float a)
{
    return a*a;
}
float calc(float a,float b)
{
    return a*b;
}
float calc(float a,float b,float c)
{
    return a+b+c;
}