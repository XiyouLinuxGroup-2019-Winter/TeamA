#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using std::string;
using std::vector;
int main()
{
    vector<int> v1(10);
    vector<int> v2{10};
    vector<int>v3(10,1);
    vector<int>v4{10,1};
    
    // vector<string> v5("haha");
    vector<string> v5(10);

    vector<string> v6{"hi"};
    vector<string> v7{10};
    vector<string> v8{10,"hi"};
    vector<int>v9;
    for (int i = 0; i < 100; i++)
    {
        v9.push_back(i);
    }
    string word;
    vector<string> text;
    while (std::cin>>word&&word!="sad")
    {
        text.push_back(word);
    }
    if(text.empty())
        std::cout<<"空的》";
    else
        std::cout<<"you";
    if(text.size()>1)
        std::cout<<"emm";
    else
        std::cout<<"ok";
    std::cout<<text[3];
    if (text==v8)
    {
        std::cout<<"容器一样？";
    }
    else
        std::cout<<"瑞有不同";
    vector<int>v{1,2,3,4,5,6,7,8,9};
    for(auto &i:v)
        i *=i;
    for (auto i : v)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    
}
