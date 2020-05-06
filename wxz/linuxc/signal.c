/*************************************************************************
	> File Name: signal.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月13日 星期一 01时36分47秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
void sig_cath(int signo)
{
    printf("catch you %d\n",signo);
}
int main()
{
    signal(SIGINT,sig_cath);
    while(1);
}
