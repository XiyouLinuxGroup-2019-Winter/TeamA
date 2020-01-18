#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
 
char a[1000005];
int b[27] = { 0 };
int main()
{
	int n, k;
	int i,j,min;
	scanf("%d%d", &n, &k);
	getchar();
	for (i = 0; i<n; i++)//9
	{
		scanf("%c", &a[i]);
		j = a[i] - 65;
		b[j]++;//b[1]==4,b[2]=2,b[3]=3
	}
	min = b[0];
	for (i = 1; i<k; i++)
	{
		if (b[i] < min)
		{
			min = b[i];//min=2
		}
	}
	printf("%d\n", min*k);//2*3
	return 0;
}
