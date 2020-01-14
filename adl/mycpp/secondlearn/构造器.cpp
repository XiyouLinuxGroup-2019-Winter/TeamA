#include <iostream>
#include <string>
#include <fstream> //文件流

class StoreQuote //类
{
public:
    std::string quote, speaker;
    std::ofstream fileOutput;

    StoreQuote();        //构造器打开文件
    ~StoreQuote();       //析构器关闭文件
    void inputQuote();   //输入一段话
    void inputSpeaker(); //输入作者
    bool write();
}; //宛如申明

StoreQuote::StoreQuote()
{
    fileOutput.open("test.txt", std::ios::app); //注意到ios就是iostream的意思，app附加
}
StoreQuote::~StoreQuote()
{
    fileOutput.close();
}
void StoreQuote::inputQuote()
{
    std::getline(std::cin, quote); //注意到直接申明了quote和下文的speaker.
}
void StoreQuote::inputSpeaker()
{
    std::getline(std::cin, speaker);
}
bool StoreQuote::write()
{
    if (fileOutput.is_open())
    {
        fileOutput << quote << "|" << speaker << "\n";
        return true;
    }
    else
    {
        return false;
    }
}
//宛如定义，放在类外面,注意到用双冒号来定义函数

int main()
{
    StoreQuote quote;
    std::cout << "请输入一句名言：\n";
    quote.inputQuote(); //注意用.来用函数，
    std::cout << "请输入作者\n";
    quote.inputSpeaker();
    if (quote.write())
    {
        std::cout << "成功写入文件";
    }
    else
    {
        std::cout << "写入文件失败";
        return 1;
    }
    return 0;
}