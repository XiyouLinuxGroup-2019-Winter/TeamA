#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
int n, c;
int x[100000000];
int cheak(int may)
{
    int i = 0;
    for (int j = 1; j < c; j++)
    {   int k=i+1;
        while (k<n&&x[k]-x[i]<may)
            k++;
        if (k == n)
            return 0;
        i=k;   
    }
    return 1;
}

int main()
{

    scanf("%d%d", &n, &c);

    int min = 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    sort(x, x + n);
    int max = x[n - 1] - x[0];

    while (max >= min)//8,0
    {
        int may = (max + min) / 2;//4//1//2//3
      //  printf("%d\n",may);
   //     if(cheak(3))
  //      printf("r");
        if (cheak(may))
            min = may + 1;//2//3
        else
            max = may - 1;//3
    }
    printf("%d", max);
}