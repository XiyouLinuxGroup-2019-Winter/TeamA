#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int n, q,Q, s[10000]={0}, ca = 0;

    while (cin>>n>>Q && (n != 0 || Q != 0))
    {
        ca++;
        for (int i = 0; i < n; i++)//4
            cin >> s[i];
        
        sort(s, s + n);
        cout << "CASE# " << ca << ":\n" ;
        for (int i = 0; i < Q; i++)
        {
            cin >> q;
            int flag=0;
            for (int j = 0; j < n; j++)
            {
                if (s[j] == q)
                {
                    cout<< q << " found at " << j+1<<endl;
                    flag=1;
                     break;
                }
            }
            if(!flag)
            cout<<q<<" not found"<<endl;
        }
    }

}