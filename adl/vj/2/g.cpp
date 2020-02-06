#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
set<string> ss;
string word;
int main()
{
    while (cin >> word)
    {
        string k = "";
        for (int i = 0; i < word.length(); i++)
        {
            if (isalpha(word[i]))
                k += tolower(word[i]);
            else if (k != "")
            {
                ss.insert(k);
                k = "";
            }
        }
        if (k != "")
            ss.insert(k);
        k = "";
    }
    for (set<string>::iterator i = ss.begin(); i != ss.end(); i++)
    {
        cout << *i << endl;
    }
}