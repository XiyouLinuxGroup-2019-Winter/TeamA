#include <iostream>
int main()
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int arr[5][5][5] = {0};
    int(&row)[4] = ia[1];
    std::cout << row[3];

    std::cout << row[4]; //that's cool!!!

    for (const auto &row : ia) //const int (&row)[4]
    {
        for (auto &col : row)
        {
            std::cout << col << std::endl;
        }
    }

    //     for ( auto row : ia)
    //     {
    //         for (auto &col : row)/*this range-based
    //         'for' statement requires a suitable "begin"
    //          function and none was found*/
    //         {
    //             std::cout << col << std::endl;
    //         }
    //     }
    for (auto p = ia; p != ia + 3; p++)
    {
        for (auto q = *p; q != *p + 4; q++)
        {
            std::cout << *q << ' ';
        }
        std::cout << std::endl;
    }
    for (auto p = std::begin(ia); p != std::end(ia); p++)
    {
        for (auto q = std::begin(*p); q != std::end(*p); q++)
        {
            std::cout << *q << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}