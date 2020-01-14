#include <iostream>

int main()
{
    char answer;
    std::cout << "请问要格式化你的硬盘？？【y/n】"
              << "\n";
    std::cin >> answer;
    switch (answer)
    {
    case 'Y':
    case 'y':
        std::cout << "随便输入是错的"
                  << "\n";
        break;
    case 'n':
    case 'N':
        std::cout << "选择明智"
                  << "\n";
        break;
    default:
        std::cout << "您的输<入不符合要求"
                  << "\n";
        break;
    }
    std::cin.ignore(100,'\n');
    std::cout << "any zifu quit"
              << "\n";
    std::cin.get();
    return 0;
}