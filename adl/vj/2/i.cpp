#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;
int main()
{
    int leader = 0, n, k;
    cin >> n >> k;
    // int s[n];
    // memset(s, 0, sizeof(s));
    // for (int i = 0; i < k; i++)
    // {
    //     int a;
    //     cin >> a;
    //     int dead = (leader + a) % n;
    //     leader = (dead + 1) % n;
    //     s[dead] = 1;
    // }
    list<int> lst;
    for (int i = 0; i < n; i++)
    {
        lst.push_back(i);
    }
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >>a;
        for (auto i = lst.begin();a; i++,a--)
        {
            
        }
    }
}