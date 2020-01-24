#include <iostream>
constexpr int size()
{
    return 2;
}
int main()
{
    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    constexpr int sz = size();
    // constexpr int * pz=&sz;
    constexpr int *pz = nullptr;
}
