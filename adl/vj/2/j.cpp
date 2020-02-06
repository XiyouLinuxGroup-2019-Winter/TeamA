#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int r, n;
    while (cin >> r >> n && (r != -1 || n != -1))
    {
        int x[n];
        for(int i=0;i<n;i++)
            cin >> x[i];
        sort(x, x + n);

        int cur = 0;
        int sum=1;
        // for (int i = 0; i < n; i++)
        //     cout<<x[i];    
        while (1)
        {
            int i = cur + 1;
            while (i != n && x[cur] + r >=x[i])
            {
                i++;
            }
            if (i == n)
                break;
            cur = i;
            cout<<cur<<endl;
            sum++;
        }
        cout<<sum<<endl;
    }
}