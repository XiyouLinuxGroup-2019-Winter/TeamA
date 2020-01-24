#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;


int main()
{
    string str("some string");
    for(auto c :str)
        cout<<c<<endl;
    string s("hello world");
    decltype(s.size())  punct_cnt=0;
    for(auto c:s)
    {
        if(ispunct(c))
            ++punct_cnt;
    }
    cout<<punct_cnt<<"punct_cnt in"<<s<<endl;
    string ss("sad");
    for(auto &c :ss)//for(auto c :ss)
        c=toupper(c);
    cout<<ss<<endl;
    return 0;
}
/*
从这个程序可以看出c本来是一个别的地方的空间，也就是c是一个原来的字符串的一个字符的拷贝
但如果用引用就可以直接改变原来的字符串的内容
*/