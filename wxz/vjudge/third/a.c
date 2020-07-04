/*************************************************************************
	> File Name: a.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 13时14分21秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    int n,m,z;
    scanf("%d %d %d",&n,&m,&z);
    int i,j;
    int cnt=0;
    for(i=1;i<=z;i++)
    {
        if(i%m==0 && i%n==0)
            cnt++;
    }
    printf("%d\n",cnt);
}
