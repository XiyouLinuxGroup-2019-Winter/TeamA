/*************************************************************************
	> File Name: alarm.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月11日 星期六 19时21分35秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
int main()
{
    int i;
    alarm(1);
    for(i=0;;i++)
    printf("%d\n",i);
}
