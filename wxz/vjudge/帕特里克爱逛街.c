/*************************************************************************
	> File Name: 帕特里克爱逛街.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 12时18分23秒
 ************************************************************************/

#include<stdio.h>
using namespace std;
int main()
{
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        int sum=a+b+c;
        sum=min(sum,(a+b)*2);
        sum=min(sum,(a+c)*2);
        sum=min(sum,(c+b)*2);
        printf("%d\n",sum);
    }
}
